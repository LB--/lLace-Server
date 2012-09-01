#ifndef __SocketServerHandler_HeaderPlusPlus__
#define __SocketServerHandler_HeaderPlusPlus__
#include "Handler.hpp"

struct ServerHandler : public virtual Handler
{
	ServerHandler(Lacewing::EventPump &EventPump);

	virtual void OnConnect(Lacewing::Server::Client &Client) = 0;
	virtual void OnReceive(Lacewing::Server::Client &Client, char *Data, int Size) = 0;
	virtual void OnDisconnect(Lacewing::Server::Client &Client) = 0;
	virtual void OnError(Lacewing::Error &Error) = 0;

	virtual ~ServerHandler();
protected:
	Lacewing::Server Server;
private:
	static void DispatchConnect(Lacewing::Server &Server, Lacewing::Server::Client &Client);
	static void DispatchReceive(Lacewing::Server &Server, Lacewing::Server::Client &Client, char *Data, int Size);
	static void DispatchDisconnect(Lacewing::Server &Server, Lacewing::Server::Client &Client);
	static void DispatchError(Lacewing::Server &Server, Lacewing::Error &Error);

	ServerHandler();
	ServerHandler(const ServerHandler &);
	ServerHandler &operator=(const ServerHandler &);
};

#endif
