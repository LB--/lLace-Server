#ifndef __DebugRelayServerHandler_HeaderPlusPlus__
#define __DebugRelayServerHandler_HeaderPlusPlus__
#include "RelayServerHandler.hpp"
#include <iostream>

class DebugRSH : public virtual RelayServerHandler
{
	//
public:
	DebugRSH(Lacewing::EventPump &EventPump, int Port = 6121) : RelayServerHandler(EventPump), Handler(EventPump)
	{
		Server.Host(Port);
		if(Server.Hosting())
		{
			std::clog << "Hosting Relay Server on port " << Server.Port() << " (debug)" << std::endl;
			Server.SetWelcomeMessage(Lacewing::Version());
		}
	}

	virtual void Tick()
	{
	}

	virtual bool OnConnect(Lacewing::RelayServer::Client &Client)
	{
		std::clog << "Client " << Client.ID() << " connected from " << Client.GetAddress().ToString() << std::endl;
		return true;
	}
	virtual void OnServerMessage(Lacewing::RelayServer::Client &Client, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
	{
		std::clog << "Client " << Client.ID() << (Blasted?" blasted":" sent") << " message on subchannel " << Subchannel << ": ";
		if(Variant == 0) std::clog << "\"" << Data << "\"";
		else if(Variant == 1) std::clog << *((int *)Data);
		else if(Variant == 2)
		{
			std::clog << '(';
			for(int i = 0; i < Size; ++i)
			{
				if(i) std::clog << ", ";
				std::clog << short(Data[i]);
			}
			std::clog << ')';
		}
		std::clog << std::endl;
	}
	virtual bool OnSetName(Lacewing::RelayServer::Client &Client, const char *name)
	{
		std::clog << "Client " << Client.ID() << " set their name to " << name << std::endl;
		return true;
	}
	virtual bool OnJoinChannel(Lacewing::RelayServer::Client &Client, Lacewing::RelayServer::Channel &Channel)
	{
		std::clog << "Client " << Client.ID() << " joined channel " << Channel.Name() << std::endl;
		return true;
	}
	virtual bool OnChannelMessage(Lacewing::RelayServer::Client &Client, Lacewing::RelayServer::Channel &Channel, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
	{
		std::clog << "Client " << Client.ID() << (Blasted?" blasted":" sent") << " message on subchannel " << Subchannel << " to channel " << Channel.Name() << ": ";
		if(Variant == 0) std::clog << "\"" << Data << "\"";
		else if(Variant == 1) std::clog << *((int *)Data);
		else if(Variant == 2)
		{
			std::clog << '(';
			for(int i = 0; i < Size; ++i)
			{
				if(i) std::clog << ", ";
				std::clog << short(Data[i]);
			}
			std::clog << ')';
		}
		std::clog << std::endl;
		return true;
	}
	virtual bool OnPeerMessage(Lacewing::RelayServer::Client &Source, Lacewing::RelayServer::Channel &Channel, Lacewing::RelayServer::Client &Target, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
	{
		std::clog << "Client " << Source.ID() << (Blasted?" blasted":" sent") << " message on subchannel " << Subchannel << " to Client " << Target.ID() << ": ";
		if(Variant == 0) std::clog << "\"" << Data << "\"";
		else if(Variant == 1) std::clog << *((int *)Data);
		else if(Variant == 2)
		{
			std::clog << '(';
			for(int i = 0; i < Size; ++i)
			{
				if(i) std::clog << ", ";
				std::clog << short(Data[i]);
			}
			std::clog << ')';
		}
		std::clog << std::endl;
		return true;
	}
	virtual bool OnLeaveChannel(Lacewing::RelayServer::Client &Client, Lacewing::RelayServer::Channel &Channel)
	{
		std::clog << "Client " << Client.ID() << " left channel " << Channel.Name() << std::endl;
		return true;
	}
	virtual void OnDisconnect(Lacewing::RelayServer::Client &Client)
	{
		std::clog << "Client " << Client.ID() << " disconnected" << std::endl;
	}
	virtual void OnError(Lacewing::Error &Error)
	{
		std::cerr << "Debug Relay Server Error: " << Error.ToString() << std::endl;
	}

	virtual ~DebugRSH()
	{
	}
private:
	DebugRSH();
	DebugRSH(const DebugRSH &);
	DebugRSH &operator=(const DebugRSH &);
};

#endif
