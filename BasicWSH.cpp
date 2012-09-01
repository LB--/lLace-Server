#include "BasicWSH.hpp"
#include <string>
#include <Windows.h>

void BasicWSH::OnGet(Lacewing::Webserver::Request &Request)
{
	std::string p = Request.URL();
	if(Lacewing::FileExists(p.c_str()))
	{
		Request.GuessMimeType(p.c_str());
		Request.SendFile(p.c_str());
	}
	else if(Lacewing::PathExists(p.c_str()) || p.empty())
	{
		if(!p.empty() && *(p.end()-1) != '/') p += '/';
		if(Lacewing::FileExists((p+"index.html").c_str()))
		{
			Request.GuessMimeType((p+"index.html").c_str());
			Request.SendFile((p+"index.html").c_str());
		}
		else
		{
			Request.Status(300, "No index found, Multiple Choices");
			WIN32_FIND_DATA fd;
			HANDLE file = FindFirstFile((p+"*").c_str(), &fd);
			do
			{
				if(file != INVALID_HANDLE_VALUE)
				{
					Request << "<a href=\"" << fd.cFileName << "\">" << fd.cFileName << "</a><br />";
				}
			}while(FindNextFile(file, &fd) != 0);
			FindClose(file);
		}
	}
	else
	{
		Request.Status(404, "No such file or directory");
		Request << "<b>" << p.c_str() << "</b> was not found as either a file or a directory.";
	}
}
