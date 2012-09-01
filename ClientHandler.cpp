#include "ClientHandler.hpp"

ClientHandler::ClientHandler(Lacewing::EventPump &EventPump) : Client(EventPump), Handler(EventPump)
{
	Client.Tag = this;
	Client.onConnect(&DispatchConnect);
	Client.onReceive(&DispatchReceive);
	Client.onDisconnect(&DispatchDisconnect);
	Client.onError(&DispatchError);
}
ClientHandler::~ClientHandler()
{
}

void ClientHandler::DispatchConnect(Lacewing::Client &Client)
{
	((ClientHandler*)Client.Tag)->OnConnect();
}
void ClientHandler::DispatchReceive(Lacewing::Client &Client, char *Data, int Size)
{
	((ClientHandler*)Client.Tag)->OnReceive(Data, Size);
}
void ClientHandler::DispatchDisconnect(Lacewing::Client &Client)
{
	((ClientHandler*)Client.Tag)->OnDisconnect();
}
void ClientHandler::DispatchError(Lacewing::Client &Client, Lacewing::Error &Error)
{
	((ClientHandler*)Client.Tag)->OnError(Error);
}
