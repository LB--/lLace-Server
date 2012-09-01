#ifndef __DebugRelayClientHandler_HeaderPlusPlus__
#define __DebugRelayClientHandler_HeaderPlusPlus__
#include "RelayClientHandler.hpp"
#include "TimerHandler.hpp"
#include <iostream>
#include <string>

class DebugRCH : public virtual RelayClientHandler, private virtual TimerHandler
{
	static const int ChannelListingWaitTime = 60000;
	std::string host;
	int port;
public:
	DebugRCH(Lacewing::EventPump &EventPump, const char *Host = "localhost", int Port = 6121) : RelayClientHandler(EventPump), TimerHandler(EventPump), Handler(EventPump), host(Host), port(Port)
	{
		Client.Connect(Host, Port);
		if(Client.Connecting())
		{
			std::clog << "Connecting to " << Host << " on port " << Port << std::endl;
		}
	}

	virtual void Tick()
	{
	}

	virtual void OnTick()
	{
		Timer.Stop();
		Client.ListChannels();
	}

	virtual void OnConnect()
	{
		Timer.Start(0);
		std::clog << "Connected to " << Client.ServerAddress().ToString() << std::endl;
		std::clog << "\tWelcome Message: " << Client.WelcomeMessage() << std::endl;
	}
	virtual void OnConnectionDenied(const char *DenyReason)
	{
		std::cerr << "Connection denied: " << DenyReason << std::endl;
	}
	virtual void OnServerMessage(bool Blasted, int Subchannel, char *Data, int Size, int Variant)
	{
	}
	virtual void OnNameSet()
	{
	}
	virtual void OnNameDenied(const char *Name, const char *DenyReason)
	{
	}
	virtual void OnNameChanged(const char *OldName)
	{
	}
	virtual void OnChannelListReceived()
	{
		Lacewing::RelayClient::ChannelListing *ChannelListing = Client.FirstChannelListing();
		std::clog << "Channel List:" << std::endl;
		if(!ChannelListing)
		{
			std::clog << "\tNo public channels" << std::endl;
		}
		else do
		{
			std::clog << "\t" << ChannelListing->Name << " (" << ChannelListing->PeerCount << ")" << std::endl;
		}while(ChannelListing = ChannelListing->Next());
		Timer.Start(ChannelListingWaitTime);
	}
	virtual void OnJoin(Lacewing::RelayClient::Channel &Channel)
	{
	}
	virtual void OnJoinDenied(const char *ChannelName, const char *DenyReason)
	{
	}
	virtual void OnServerChannelMessage(Lacewing::RelayClient::Channel &Channel, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
	{
	}
	virtual void OnChannelMessage(Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
	{
	}
	virtual void OnPeerConnect(Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer)
	{
	}
	virtual void OnPeerMessage(Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
	{
	}
	virtual void OnPeerChangeName(Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer, const char *OldName)
	{
	}
	virtual void OnPeerDisconnect(Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer)
	{
	}
	virtual void OnLeave(Lacewing::RelayClient::Channel &Channel)
	{
	}
	virtual void OnLeaveDenied(Lacewing::RelayClient::Channel &Channel, const char *DenyReason)
	{
	}
	virtual void OnDisconnect()
	{
		Timer.Stop();
		std::clog << "Disconnected" << std::endl;
		Client.Connect(host.c_str(), port);
	}
	virtual void OnError(Lacewing::Error &Error)
	{
		std::cerr << "Relay Client Error: " << Error.ToString() << std::endl;
	}

	virtual ~DebugRCH()
	{
	}
private:
	DebugRCH();
	DebugRCH(const DebugRCH &);
	DebugRCH &operator=(const DebugRCH &);
};

#endif
