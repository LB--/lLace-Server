#ifndef __FlashPlayerPolicyHandler_HeaderPlusPlus__
#define __FlashPlayerPolicyHandler_HeaderPlusPlus__
#include "Handler.hpp"

struct FlashPolicyHandler : public virtual Handler
{
	FlashPolicyHandler(Lacewing::EventPump &EventPump);

	virtual void OnError(Lacewing::Error &Error) = 0;

	virtual ~FlashPolicyHandler();
protected:
	Lacewing::FlashPolicy Server;
private:
	static void DispatchError(Lacewing::FlashPolicy &Server, Lacewing::Error &Error);

	FlashPolicyHandler();
	FlashPolicyHandler(const FlashPolicyHandler &);
	FlashPolicyHandler &operator=(const FlashPolicyHandler &);
};

#endif
