#ifndef __RelayServerHandler_HeaderPlusPlus__
#define __RelayServerHandler_HeaderPlusPlus__
#include "Handler.hpp"

struct RelayServerHandler : public virtual Handler
{
	RelayServerHandler(Lacewing::EventPump &EventPump);

	virtual bool OnConnect(Lacewing::RelayServer::Client &Client) = 0;
	virtual void OnServerMessage(Lacewing::RelayServer::Client &Client, bool Blasted, int Subchannel, char *Data, int Size, int Variant) = 0;
	virtual bool OnSetName(Lacewing::RelayServer::Client &Client, const char *name) = 0;
	virtual bool OnJoinChannel(Lacewing::RelayServer::Client &Client, Lacewing::RelayServer::Channel &Channel) = 0;
	virtual bool OnChannelMessage(Lacewing::RelayServer::Client &Client, Lacewing::RelayServer::Channel &Channel, bool Blasted, int Subchannel, char *Data, int Size, int Variant) = 0;
	virtual bool OnPeerMessage(Lacewing::RelayServer::Client &Source, Lacewing::RelayServer::Channel &Channel, Lacewing::RelayServer::Client &Target, bool Blasted, int Subchannel, char *Data, int Size, int Variant) = 0;
	virtual bool OnLeaveChannel(Lacewing::RelayServer::Client &Client, Lacewing::RelayServer::Channel &Channel) = 0;
	virtual void OnDisconnect(Lacewing::RelayServer::Client &Client) = 0;
	virtual void OnError(Lacewing::Error &Error) = 0;

	virtual ~RelayServerHandler();
protected:
	Lacewing::RelayServer Server;
private:
	static bool DispatchConnect(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Client);
	static void DispatchServerMessage(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Client, bool Blasted, int Subchannel, char *Data, int Size, int Variant);
	static bool DispatchSetName(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Client, const char *name);
	static bool DispatchJoinChannel(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Client, Lacewing::RelayServer::Channel &Channel);
	static bool DispatchChannelMessage(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Client, Lacewing::RelayServer::Channel &Channel, bool Blasted, int Subchannel, char *Data, int Size, int Variant);
	static bool DispatchPeerMessage(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Source, Lacewing::RelayServer::Channel &Channel, Lacewing::RelayServer::Client &Target, bool Blasted, int Subchannel, char *Data, int Size, int Variant);
	static bool DispatchLeaveChannel(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Client, Lacewing::RelayServer::Channel &Channel);
	static void DispatchDisconnect(Lacewing::RelayServer &Server, Lacewing::RelayServer::Client &Client);
	static void DispatchError(Lacewing::RelayServer &Server, Lacewing::Error &Error);

	RelayServerHandler();
	RelayServerHandler(const RelayServerHandler &);
	RelayServerHandler &operator=(const RelayServerHandler &);
};

#endif
