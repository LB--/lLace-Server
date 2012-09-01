#ifndef __BasicFlashPlayerPolicyHandler_HeaderPlusPlus__
#define __BasicFlashPlayerPolicyHandler_HeaderPlusPlus__
#include "FlashPolicyHandler.hpp"
#include <iostream>

struct BasicFPH : public virtual FlashPolicyHandler
{
	BasicFPH(Lacewing::EventPump &EventPump, const char *Filename = "crossdomain.xml") : FlashPolicyHandler(EventPump), Handler(EventPump)
	{
		Server.Host(Filename);
		if(Server.Hosting())
		{
			std::clog << "Hosting \"" << Filename << "\"" << std::endl;
		}
	}

	virtual void Tick()
	{
	}

	virtual void OnError(Lacewing::Error &Error)
	{
		std::cerr << "Flash Policy Error: " << Error.ToString() << std::endl;
	}

	virtual ~BasicFPH()
	{
	}
private:
	BasicFPH();
	BasicFPH(const BasicFPH &);
	BasicFPH &operator=(const BasicFPH &);
};

#endif
