#ifndef __Handler_HeaderPlusPlus__
#define __Handler_HeaderPlusPlus__
#include "Lacewing.h"

struct Handler
{
	Handler(Lacewing::EventPump &EventPump);

	virtual void Tick() = 0;

	virtual ~Handler();
protected:
	Lacewing::EventPump &EventPump;
private:
	static void DispatchTick(Handler *h);

	Handler();
	Handler(const Handler &);
	Handler &operator=(const Handler &);
};

#endif
