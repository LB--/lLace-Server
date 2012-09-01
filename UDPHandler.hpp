#ifndef __SocketClientHandler_HeaderPlusPlus__
#define __SocketClientHandler_HeaderPlusPlus__
#include "Handler.hpp"

struct UDPHandler : public virtual Handler
{
	UDPHandler(Lacewing::EventPump &EventPump);

	virtual void OnReceive(Lacewing::Address &Address, char *Data, int Size) = 0;
	virtual void OnError(Lacewing::Error &Error) = 0;

	virtual ~UDPHandler();
protected:
	Lacewing::UDP UDP;
private:
	static void DispatchReceive(Lacewing::UDP &UDP, Lacewing::Address &Address, char *Data, int Size);
	static void DispatchError(Lacewing::UDP &UDP, Lacewing::Error &Error);

	UDPHandler();
	UDPHandler(const UDPHandler &);
	UDPHandler &operator=(const UDPHandler &);
};

#endif
