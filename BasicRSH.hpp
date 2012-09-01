#ifndef __BasicRelayServerHandler_HeaderPlusPlus__
#define __BasicRelayServerHandler_HeaderPlusPlus__
#include "RelayServerHandler.hpp"
#include <iostream>

struct BasicRSH : public virtual RelayServerHandler
{
	BasicRSH(Lacewing::EventPump &EventPump, int Port = 6121) : RelayServerHandler(EventPump), Handler(EventPump)
	{
		Server.Host(Port);
		if(Server.Hosting())
		{
			std::clog << "Hosting Relay Server on port " << Server.Port() << std::endl;
			Server.SetWelcomeMessage(Lacewing::Version());
		}
	}

	virtual void Tick()
	{
	}

	virtual bool OnConnect(Lacewing::RelayServer::Client &Client)
	{
		return true;
	}
	virtual void OnServerMessage(Lacewing::RelayServer::Client &Client, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
	{
	}
	virtual bool OnSetName(Lacewing::RelayServer::Client &Client, const char *name)
	{
		return true;
	}
	virtual bool OnJoinChannel(Lacewing::RelayServer::Client &Client, Lacewing::RelayServer::Channel &Channel)
	{
		return true;
	}
	virtual bool OnChannelMessage(Lacewing::RelayServer::Client &Client, Lacewing::RelayServer::Channel &Channel, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
	{
		return true;
	}
	virtual bool OnPeerMessage(Lacewing::RelayServer::Client &Source, Lacewing::RelayServer::Channel &Channel, Lacewing::RelayServer::Client &Target, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
	{
		return true;
	}
	virtual bool OnLeaveChannel(Lacewing::RelayServer::Client &Client, Lacewing::RelayServer::Channel &Channel)
	{
		return true;
	}
	virtual void OnDisconnect(Lacewing::RelayServer::Client &Client)
	{
	}
	virtual void OnError(Lacewing::Error &Error)
	{
		std::cerr << "Relay Server Error: " << Error.ToString() << std::endl;
	}

	virtual ~BasicRSH()
	{
	}
private:
	BasicRSH();
	BasicRSH(const BasicRSH &);
	BasicRSH &operator=(const BasicRSH &);
};

#endif
