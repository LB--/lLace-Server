#include "RelayClientHandler.hpp"

RelayClientHandler::RelayClientHandler(Lacewing::EventPump &EventPump) : Client(EventPump), Handler(EventPump)
{
	Client.Tag = this;
	Client.onConnect(&DispatchConnect);
	Client.onConnectionDenied(&DispatchConnectionDenied);
	Client.onServerMessage(&DispatchServerMessage);
	Client.onNameSet(&DispatchNameSet);
	Client.onNameDenied(&DispatchNameDenied);
	Client.onNameChanged(&DispatchNameChanged);
	Client.onChannelListReceived(&DispatchChannelListReceived);
	Client.onJoin(&DispatchJoin);
	Client.onJoinDenied(&DispatchJoinDenied);
	Client.onServerChannelMessage(&DispatchServerChannelMessage);
	Client.onChannelMessage(&DispatchChannelMessage);
	Client.onPeerConnect(&DispatchPeerConnect);
	Client.onPeerMessage(&DispatchPeerMessage);
	Client.onPeerChangeName(&DispatchPeerChangeName);
	Client.onPeerDisconnect(&DispatchPeerDisconnect);
	Client.onLeave(&DispatchLeave);
	Client.onLeaveDenied(&DispatchLeaveDenied);
	Client.onDisconnect(&DispatchDisconnect);
	Client.onError(&DispatchError);
}
RelayClientHandler::~RelayClientHandler()
{
}

void RelayClientHandler::DispatchConnect(Lacewing::RelayClient &Client)
{
	((RelayClientHandler*)Client.Tag)->OnConnect();
}
void RelayClientHandler::DispatchConnectionDenied(Lacewing::RelayClient &Client, const char *DenyReason)
{
	((RelayClientHandler*)Client.Tag)->OnConnectionDenied(DenyReason);
}
void RelayClientHandler::DispatchServerMessage(Lacewing::RelayClient &Client, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
{
	((RelayClientHandler*)Client.Tag)->OnServerMessage(Blasted, Subchannel, Data, Size, Variant);
}
void RelayClientHandler::DispatchNameSet(Lacewing::RelayClient &Client)
{
	((RelayClientHandler*)Client.Tag)->OnNameSet();
}
void RelayClientHandler::DispatchNameDenied(Lacewing::RelayClient &Client, const char *Name, const char *DenyReason)
{
	((RelayClientHandler*)Client.Tag)->OnNameDenied(Name, DenyReason);
}
void RelayClientHandler::DispatchNameChanged(Lacewing::RelayClient &Client, const char *OldName)
{
	((RelayClientHandler*)Client.Tag)->OnNameChanged(OldName);
}
void RelayClientHandler::DispatchChannelListReceived(Lacewing::RelayClient &Client)
{
	((RelayClientHandler*)Client.Tag)->OnChannelListReceived();
}
void RelayClientHandler::DispatchJoin(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel)
{
	((RelayClientHandler*)Client.Tag)->OnJoin(Channel);
}
void RelayClientHandler::DispatchJoinDenied(Lacewing::RelayClient &Client, const char *ChannelName, const char *DenyReason)
{
	((RelayClientHandler*)Client.Tag)->OnJoinDenied(ChannelName, DenyReason);
}
void RelayClientHandler::DispatchServerChannelMessage(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
{
	((RelayClientHandler*)Client.Tag)->OnServerChannelMessage(Channel, Blasted, Subchannel, Data, Size, Variant);
}
void RelayClientHandler::DispatchChannelMessage(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
{
	((RelayClientHandler*)Client.Tag)->OnChannelMessage(Channel, Peer, Blasted, Subchannel, Data, Size, Variant);
}
void RelayClientHandler::DispatchPeerConnect(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer)
{
	((RelayClientHandler*)Client.Tag)->OnPeerConnect(Channel, Peer);
}
void RelayClientHandler::DispatchPeerMessage(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
{
	((RelayClientHandler*)Client.Tag)->OnPeerMessage(Channel, Peer, Blasted, Subchannel, Data, Size, Variant);
}
void RelayClientHandler::DispatchPeerChangeName(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer, const char *OldName)
{
	((RelayClientHandler*)Client.Tag)->OnPeerChangeName(Channel, Peer, OldName);
}
void RelayClientHandler::DispatchPeerDisconnect(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel, Lacewing::RelayClient::Channel::Peer &Peer)
{
	((RelayClientHandler*)Client.Tag)->OnPeerDisconnect(Channel, Peer);
}
void RelayClientHandler::DispatchLeave(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel)
{
	((RelayClientHandler*)Client.Tag)->OnLeave(Channel);
}
void RelayClientHandler::DispatchLeaveDenied(Lacewing::RelayClient &Client, Lacewing::RelayClient::Channel &Channel, const char *DenyReason)
{
	((RelayClientHandler*)Client.Tag)->OnLeaveDenied(Channel, DenyReason);
}
void RelayClientHandler::DispatchDisconnect(Lacewing::RelayClient &Client)
{
	((RelayClientHandler*)Client.Tag)->OnDisconnect();
}
void RelayClientHandler::DispatchError(Lacewing::RelayClient &Client, Lacewing::Error &Error)
{
	((RelayClientHandler*)Client.Tag)->OnError(Error);
}
