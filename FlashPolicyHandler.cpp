#include "FlashPolicyHandler.hpp"

FlashPolicyHandler::FlashPolicyHandler(Lacewing::EventPump &EventPump) : Server(EventPump), Handler(EventPump)
{
	Server.Tag = this;
	Server.onError(&DispatchError);
}
FlashPolicyHandler::~FlashPolicyHandler()
{
}

void FlashPolicyHandler::DispatchError(Lacewing::FlashPolicy &Server, Lacewing::Error &Error)
{
	((FlashPolicyHandler*)Server.Tag)->OnError(Error);
}
