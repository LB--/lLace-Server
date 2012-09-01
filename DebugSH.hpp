#ifndef __DebugServerHandler_HeaderPlusPlus__
#define __DebugServerHandler_HeaderPlusPlus__
#include "ServerHandler.hpp"
#include <iostream>

class DebugSH : public virtual ServerHandler
{
	//
public:
	DebugSH(Lacewing::EventPump &EventPump, int Port) : ServerHandler(EventPump), Handler(EventPump)
	{
		Server.Host(Port);
		if(Server.Hosting())
		{
			std::clog << "Hosting Server on port " << Server.Port() << " (debug)" << std::endl;
		}
	}

	virtual void Tick()
	{
	}

	virtual void OnConnect(Lacewing::Server::Client &Client)
	{
		std::clog << "Client " << Client.GetAddress().ToString() << " connected" << std::endl;
	}
	virtual void OnReceive(Lacewing::Server::Client &Client, char *Data, int Size)
	{
		std::clog << "Client " << Client.GetAddress().ToString() << " sent: ";
		std::clog.write(Data, Size) << std::endl;
	}
	virtual void OnDisconnect(Lacewing::Server::Client &Client)
	{
		std::clog << "Client " << Client.GetAddress().ToString() << " disconnected" << std::endl;
	}
	virtual void OnError(Lacewing::Error &Error)
	{
		std::cerr << "Server Error: " << Error.ToString() << std::endl;
	}

	virtual ~DebugSH()
	{
	}
private:
	DebugSH();
	DebugSH(const DebugSH &);
	DebugSH &operator=(const DebugSH &);
};

#endif
