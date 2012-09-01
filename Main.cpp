#include "Common.hpp"
#include <vector>
#include "BasicRSH.hpp"
#include "DebugRSH.hpp"
#include "BasicFPH.hpp"
#include "BasicWSH.hpp"
#include "DebugUDPH.hpp"
#include "DebugSH.hpp"
#include "DebugRCH.hpp"

int main(int nargs, const char *args[])
{
	std::clog << Lacewing::Version() << std::endl;

	Lacewing::EventPump EventPump;

	typedef std::vector<Handler *> Handlers_t;
	Handlers_t Handlers;

//	Handlers.push_back(new BasicRSH(EventPump));
	Handlers.push_back(new DebugRSH(EventPump, 6122));
	Handlers.push_back(new BasicFPH(EventPump));
//	Handlers.push_back(new BasicWSH(EventPump));
	Handlers.push_back(new DebugUDPH(EventPump, 7));
	Handlers.push_back(new DebugSH(EventPump, 7));
//	Handlers.push_back(new DebugRCH(EventPump, "localhost", 6121));

	Lacewing::Error *Error = EventPump.StartEventLoop();
	if(Error)
	{
		std::cerr << "Event Pump Error: " << Error->ToString() << std::endl;
		int x;std::cin>>x;
		delete Error;
	}

	for(Handlers_t::iterator it = Handlers.begin(); it != Handlers.end(); ++it)
	{
		delete *it;
	}
}
