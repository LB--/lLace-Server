#ifndef __WebServerHandler_HeaderPlusPlus__
#define __WebServerHandler_HeaderPlusPlus__
#include "Handler.hpp"

struct WebServerHandler : public Handler
{
	WebServerHandler(Lacewing::EventPump &EventPump);

	virtual void OnHead(Lacewing::Webserver::Request &Request) = 0;
	virtual void OnGet(Lacewing::Webserver::Request &Request) = 0;
	virtual void OnPost(Lacewing::Webserver::Request &Request) = 0;
	virtual void OnUploadStart(Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload &Upload) = 0;
	virtual void OnUploadChunk(Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload &Upload, const char *Data, int Size) = 0;
	virtual void OnUploadDone(Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload &Upload) = 0;
	virtual void OnUploadPost(Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload *Uploads[], int UploadCount) = 0;
	virtual void OnDisconnect(Lacewing::Webserver::Request &Request) = 0;
	virtual void OnError(Lacewing::Error &Error) = 0;

	virtual ~WebServerHandler();
protected:
	Lacewing::Webserver Server;
private:
	static void DispatchHead(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request);
	static void DispatchGet(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request);
	static void DispatchPost(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request);
	static void DispatchUploadStart(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload &Upload);
	static void DispatchUploadChunk(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload &Upload, const char *Data, int Size);
	static void DispatchUploadDone(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload &Upload);
	static void DispatchUploadPost(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request, Lacewing::Webserver::Upload *Uploads[], int UploadCount);
	static void DispatchDisconnect(Lacewing::Webserver &Server, Lacewing::Webserver::Request &Request);
	static void DispatchError(Lacewing::Webserver &Server, Lacewing::Error &Error);

	WebServerHandler();
	WebServerHandler(const WebServerHandler &);
	WebServerHandler &operator=(const WebServerHandler &);
};

#endif
