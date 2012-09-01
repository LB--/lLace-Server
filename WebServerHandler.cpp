#include "WebServerHandler.hpp"

WebServerHandler::WebServerHandler(Lacewing::EventPump &EventPump) : Server(EventPump), Handler(EventPump)
{
	Server.Tag = this;
	Server.onHead(&DispatchHead);
	Server.onGet(&DispatchGet);
	Server.onPost(&DispatchPost);
	Server.onUploadStart(&DispatchUploadStart);
	Server.onUploadChunk(&DispatchUploadChunk);
	Server.onUploadDone(&DispatchUploadDone);
	Server.onUploadPost(&DispatchUploadPost);
	Server.onDisconnect(&DispatchDisconnect);
	Server.onError(&DispatchError);
}
WebServerHandler::~WebServerHandler()
{
}

void WebServerHandler::DispatchHead(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request)
{
	((WebServerHandler*)Server.Tag)->OnHead(Request);
}
void WebServerHandler::DispatchGet(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request)
{
	((WebServerHandler*)Server.Tag)->OnGet(Request);
}
void WebServerHandler::DispatchPost(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request)
{
	((WebServerHandler*)Server.Tag)->OnPost(Request);
}
void WebServerHandler::DispatchUploadStart(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload &Upload)
{
	((WebServerHandler*)Server.Tag)->OnUploadStart(Request, Upload);
}
void WebServerHandler::DispatchUploadChunk(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload &Upload, const char *Data, int Size)
{
	((WebServerHandler*)Server.Tag)->OnUploadChunk(Request, Upload, Data, Size);
}
void WebServerHandler::DispatchUploadDone(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload &Upload)
{
	((WebServerHandler*)Server.Tag)->OnUploadDone(Request, Upload);
}
void WebServerHandler::DispatchUploadPost(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload *Uploads[], int UploadCount)
{
	((WebServerHandler*)Server.Tag)->OnUploadPost(Request, Uploads, UploadCount);
}
void WebServerHandler::DispatchDisconnect(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request)
{
	((WebServerHandler*)Server.Tag)->OnDisconnect(Request);
}
void WebServerHandler::DispatchError(Lacewing::Webserver &Server, Lacewing::Error &Error)
{
	((WebServerHandler*)Server.Tag)->OnError(Error);
}
