#include "Handler.hpp"

Handler::Handler(Lacewing::EventPump &EventPump) : EventPump(EventPump)
{
	EventPump.Post(&DispatchTick, this);
}
Handler::~Handler()
{
}

void Handler::DispatchTick(Handler *h)
{
	h->Tick();
	h->EventPump.Post(&DispatchTick, h);
}
