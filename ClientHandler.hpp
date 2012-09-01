#ifndef __SocketClientHandler_HeaderPlusPlus__
#define __SocketClientHandler_HeaderPlusPlus__
#include "Handler.hpp"

struct ClientHandler : public virtual Handler
{
	ClientHandler(Lacewing::EventPump &EventPump);

	virtual void OnConnect() = 0;
	virtual void OnReceive(char *Data, int Size) = 0;
	virtual void OnDisconnect() = 0;
	virtual void OnError(Lacewing::Error &Error) = 0;

	virtual ~ClientHandler();
protected:
	Lacewing::Client Client;
private:
	static void DispatchConnect(Lacewing::Client &Client);
	static void DispatchReceive(Lacewing::Client &Client, char *Data, int Size);
	static void DispatchDisconnect(Lacewing::Client &Client);
	static void DispatchError(Lacewing::Client &Client, Lacewing::Error &Error);

	ClientHandler();
	ClientHandler(const ClientHandler &);
	ClientHandler &operator=(const ClientHandler &);
};

#endif
