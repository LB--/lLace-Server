#ifndef __RelayClientHandler_HeaderPlusPlus__
#define __RelayClientHandler_HeaderPlusPlus__
#include "Handler.hpp"

struct RelayClientHandler : public virtual Handler
{
	RelayClientHandler(Lacewing::EventPump &EventPump);

	virtual void OnConnect() = 0;
	virtual void OnConnectionDenied(const char *DenyReason) = 0;
	virtual void OnServerMessage(bool Blasted, int Subchannel, char *Data, int Size, int Variant) = 0;
	virtual void OnNameSet() = 0;
	virtual void OnNameDenied(const char *Name, const char *DenyReason) = 0;
	virtual void OnNameChanged(const char *OldName) = 0;
	virtual void OnChannelListReceived() = 0;
	virtual void OnJoin(Lacewing::RelayClient::Channel &Channel) = 0;
	virtual void OnJoinDenied(const char *ChannelName, const char *DenyReason) = 0;
	virtual void OnServerChannelMessage(Lacewing::RelayClient::Channel &Channel, bool Blasted, int Subchannel, char *Data, int Size, int Variant) = 0;
	virtual void OnChannelMessage(Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer, bool Blasted, int Subchannel, char *Data, int Size, int Variant) = 0;
	virtual void OnPeerConnect(Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer) = 0;
	virtual void OnPeerMessage(Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer, bool Blasted, int Subchannel, char *Data, int Size, int Variant) = 0;
	virtual void OnPeerChangeName(Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer, const char *OldName) = 0;
	virtual void OnPeerDisconnect(Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer) = 0;
	virtual void OnLeave(Lacewing::RelayClient::Channel &Channel) = 0;
	virtual void OnLeaveDenied(Lacewing::RelayClient::Channel &Channel, const char *DenyReason) = 0;
	virtual void OnDisconnect() = 0;
	virtual void OnError(Lacewing::Error &Error) = 0;

	virtual ~RelayClientHandler();
protected:
	Lacewing::RelayClient Client;
private:
	static void DispatchConnect(Lacewing::RelayClient &Client);
	static void DispatchConnectionDenied(Lacewing::RelayClient &Client, const char *DenyReason);
	static void DispatchServerMessage(Lacewing::RelayClient &Client, bool Blasted, int Subchannel, char *Data, int Size, int Variant);
	static void DispatchNameSet(Lacewing::RelayClient &Client);
	static void DispatchNameDenied(Lacewing::RelayClient &Client, const char *Name, const char *DenyReason);
	static void DispatchNameChanged(Lacewing::RelayClient &Client, const char *OldName);
	static void DispatchChannelListReceived(Lacewing::RelayClient &Client);
	static void DispatchJoin(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel);
	static void DispatchJoinDenied(Lacewing::RelayClient &Client, const char *ChannelName, const char *DenyReason);
	static void DispatchServerChannelMessage(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel, bool Blasted, int Subchannel, char *Data, int Size, int Variant);
	static void DispatchChannelMessage(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer, bool Blasted, int Subchannel, char *Data, int Size, int Variant);
	static void DispatchPeerConnect(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer);
	static void DispatchPeerMessage(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer, bool Blasted, int Subchannel, char *Data, int Size, int Variant);
	static void DispatchPeerChangeName(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer, const char *OldName);
	static void DispatchPeerDisconnect(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer);
	static void DispatchLeave(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel);
	static void DispatchLeaveDenied(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel, const char *DenyReason);
	static void DispatchDisconnect(Lacewing::RelayClient &Client);
	static void DispatchError(Lacewing::RelayClient &Client, Lacewing::Error &Error);

	RelayClientHandler();
	RelayClientHandler(const RelayClientHandler &);
	RelayClientHandler &operator=(const RelayClientHandler &);
};

#endif
