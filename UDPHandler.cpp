#include "UDPHandler.hpp"

UDPHandler::UDPHandler(Lacewing::EventPump &EventPump) : UDP(EventPump), Handler(EventPump)
{
	UDP.Tag = this;
	UDP.onReceive(&DispatchReceive);
	UDP.onError(&DispatchError);
}
UDPHandler::~UDPHandler()
{
}

void UDPHandler::DispatchReceive(Lacewing::UDP &UDP, Lacewing::Address &Address, char *Data, int Size)
{
	((UDPHandler*)UDP.Tag)->OnReceive(Address, Data, Size);
}
void UDPHandler::DispatchError(Lacewing::UDP &UDP, Lacewing::Error &Error)
{
	((UDPHandler*)UDP.Tag)->OnError(Error);
}
