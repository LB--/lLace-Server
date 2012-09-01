#ifndef __DebugUDPHandler_HeaderPlusPlus__
#define __DebugUDPHandler_HeaderPlusPlus__
#include "UDPHandler.hpp"
#include <iostream>

class DebugUDPH : public virtual UDPHandler
{
	//
public:
	DebugUDPH(Lacewing::EventPump &EventPump, int Port) : UDPHandler(EventPump), Handler(EventPump)
	{
		UDP.Host(Port);
		if(UDP.Hosting())
		{
			std::clog << "Hosting UDP on port " << UDP.Port() << " (debug)" << std::endl;
		}
	}

	virtual void Tick()
	{
	}

	virtual void OnReceive(Lacewing::Address &Address, char *Data, int Size)
	{
		std::clog << "From " << Address.ToString() << " received: ";
		std::clog.write(Data, Size) << std::endl;
	}
	virtual void OnError(Lacewing::Error &Error)
	{
		std::cerr << "UDP Error: " << Error.ToString() << std::endl;
	}

	virtual ~DebugUDPH()
	{
	}
private:
	DebugUDPH();
	DebugUDPH(const DebugUDPH &);
	DebugUDPH &operator=(const DebugUDPH &);
};

#endif
