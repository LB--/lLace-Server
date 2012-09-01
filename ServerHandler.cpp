#include "ServerHandler.hpp"

ServerHandler::ServerHandler(Lacewing::EventPump &EventPump) : Server(EventPump), Handler(EventPump)
{
	Server.Tag = this;
	Server.onConnect(&DispatchConnect);
	Server.onReceive(&DispatchReceive);
	Server.onDisconnect(&DispatchDisconnect);
	Server.onError(&DispatchError);
}
ServerHandler::~ServerHandler()
{
}

void ServerHandler::DispatchConnect(Lacewing::Server &Server, Lacewing::Server::Client &Client)
{
	((ServerHandler*)Server.Tag)->OnConnect(Client);
}
void ServerHandler::DispatchReceive(Lacewing::Server &Server, Lacewing::Server::Client &Client, char *Data, int Size)
{
	((ServerHandler*)Server.Tag)->OnReceive(Client, Data, Size);
}
void ServerHandler::DispatchDisconnect(Lacewing::Server &Server, Lacewing::Server::Client &Client)
{
	((ServerHandler*)Server.Tag)->OnDisconnect(Client);
}
void ServerHandler::DispatchError(Lacewing::Server &Server, Lacewing::Error &Error)
{
	((ServerHandler*)Server.Tag)->OnError(Error);
}
