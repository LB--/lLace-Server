#ifndef __TimerHandler_HeaderPlusPlus__
#define __TimerHandler_HeaderPlusPlus__
#include "Handler.hpp"

struct TimerHandler : protected virtual Handler
{
	TimerHandler(Lacewing::EventPump &EventPump);

	virtual void OnTick() = 0;

	virtual ~TimerHandler();
protected:
	Lacewing::Timer Timer;
	virtual void Tick();
private:
	static void DispatchTick(Lacewing::Timer &Timer);

	TimerHandler();
	TimerHandler(const TimerHandler &);
	TimerHandler &operator=(const TimerHandler &);
};

#endif
