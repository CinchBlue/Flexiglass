#include "Event_Listener.hpp"

namespace flgl
{

Event_Listener::Event_Listener(Event_Receivable* owner_obj)
{
	owner = owner_obj;
}

void Event_Listener::receive_event(Event* e)
{
	std::cout << "Event received!" << std::endl;
	notify_owner(e);
}

void Event_Listener::notify_owner(Event* e)
{
	owner->on_notify(e);
}

} //namespace flgl
