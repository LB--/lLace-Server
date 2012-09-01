#ifndef __BasicWebserverHandler_HeaderPlusPlus__
#define __BasicWebserverHandler_HeaderPlusPlus__
#include "WebServerHandler.hpp"
#include <iostream>

struct BasicWSH : public virtual WebServerHandler
{
	BasicWSH(Lacewing::EventPump &EventPump, int Port = 80) : WebServerHandler(EventPump)
	{
		Server.Host(Port);
		if(Server.Hosting())
		{
			std::clog << "Hosting Webserver on port " << Server.Port() << std::endl;
		}
	}

	virtual void Tick()
	{
	}

	virtual void OnHead(Lacewing::Webserver::Request &Request)
	{
	}
	virtual void OnGet(Lacewing::Webserver::Request &Request);
	virtual void OnPost(Lacewing::Webserver::Request &Request)
	{
		Request.Status(418, "I'm a teapot");
		Request << "HTTP 418 I'm a teapot";
	}
	virtual void OnUploadStart(Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload &Upload)
	{
	}
	virtual void OnUploadChunk(Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload &Upload, const char *Data, int Size)
	{
	}
	virtual void OnUploadDone(Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload &Upload)
	{
	}
	virtual void OnUploadPost(Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload *Uploads[], int UploadCount)
	{
	}
	virtual void OnDisconnect(Lacewing::Webserver::Request &Request)
	{
	}
	virtual void OnError(Lacewing::Error &Error)
	{
		std::cerr << "Webserver Error: " << Error.ToString() << std::endl;
	}

	virtual ~BasicWSH()
	{
	}
private:
	BasicWSH();
	BasicWSH(const BasicWSH &);
	BasicWSH &operator=(const BasicWSH &);
};

#endif
