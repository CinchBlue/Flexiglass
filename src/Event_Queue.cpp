#include "Event_Queue.hpp"

namespace flgl
{

void Event_Queue::add_listener(Event_Listener* listener_ptr)
{
	listeners.push_back(listener_ptr);
}

//Returns TRUE on removing receiver
bool Event_Queue::remove_listener(Event_Listener* listener_ptr)
{
	for(auto it = listeners.begin(); it != listeners.end(); ++it)
	{
		if(*it == listener_ptr)
		{
			listeners.erase(it);
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;
}

void Event_Queue::push_event(Event& e)
{
	events.push(e);
}

Event Event_Queue::pop_event()
{
	Event temp = events.front();
	events.pop();
	return temp;
}

}//namespace flgl
