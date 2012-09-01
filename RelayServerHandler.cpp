#include "RelayServerHandler.hpp"

RelayServerHandler::RelayServerHandler(Lacewing::EventPump &EventPump) : Server(EventPump), Handler(EventPump)
{
	Server.Tag = this;
	Server.onConnect(&DispatchConnect);
	Server.onServerMessage(&DispatchServerMessage);
	Server.onSetName(&DispatchSetName);
	Server.onJoinChannel(&DispatchJoinChannel);
	Server.onChannelMessage(&DispatchChannelMessage);
	Server.onPeerMessage(&DispatchPeerMessage);
	Server.onLeaveChannel(&DispatchLeaveChannel);
	Server.onDisconnect(&DispatchDisconnect);
	Server.onError(&DispatchError);
}
RelayServerHandler::~RelayServerHandler()
{
}

bool RelayServerHandler::DispatchConnect(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Client)
{
	return ((RelayServerHandler*)Server.Tag)->OnConnect(Client);
}
void RelayServerHandler::DispatchServerMessage(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Client, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
{
	((RelayServerHandler*)Server.Tag)->OnServerMessage(Client, Blasted, Subchannel, Data, Size, Variant);
}
bool RelayServerHandler::DispatchSetName(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Client, const char *name)
{
	return ((RelayServerHandler*)Server.Tag)->OnSetName(Client, name);
}
bool RelayServerHandler::DispatchJoinChannel(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Client, Lacewing::RelayServer::Channel &Channel)
{
	return ((RelayServerHandler*)Server.Tag)->OnJoinChannel(Client, Channel);
}
bool RelayServerHandler::DispatchChannelMessage(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Client, Lacewing::RelayServer::Channel &Channel, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
{
	return ((RelayServerHandler*)Server.Tag)->OnChannelMessage(Client, Channel, Blasted, Subchannel, Data, Size, Variant);
}
bool RelayServerHandler::DispatchPeerMessage(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Source, Lacewing::RelayServer::Channel &Channel, Lacewing::RelayServer::Client &Target, bool Blasted, int Subchannel, char *Data, int Size, int Variant)
{
	return ((RelayServerHandler*)Server.Tag)->OnPeerMessage(Source, Channel, Target, Blasted, Subchannel, Data, Size, Variant);
}
bool RelayServerHandler::DispatchLeaveChannel(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Client, Lacewing::RelayServer::Channel &Channel)
{
	return ((RelayServerHandler*)Server.Tag)->OnLeaveChannel(Client, Channel);
}
void RelayServerHandler::DispatchDisconnect(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Client)
{
	((RelayServerHandler*)Server.Tag)->OnDisconnect(Client);
}
void RelayServerHandler::DispatchError(Lacewing::RelayServer &Server, Lacewing::Error &Error)
{
	((RelayServerHandler*)Server.Tag)->OnError(Error);
}
