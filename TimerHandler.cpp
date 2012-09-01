#include "Timerhandler.hpp"

TimerHandler::TimerHandler(Lacewing::EventPump &EventPump) : Timer(EventPump), Handler(EventPump)
{
	Timer.Tag = this;
	Timer.onTick(&DispatchTick);
}
TimerHandler::~TimerHandler()
{
}

void TimerHandler::Tick()
{
}

void TimerHandler::DispatchTick(Lacewing::Timer &Timer)
{
	((TimerHandler*)Timer.Tag)->OnTick();
}
