#ifndef FLEXIGLASS_EVENT_QUEUE_HPP
#define FLEXIGLASS_EVENT_QUEUE_HPP

#include "common.hpp"
#include "Event.hpp"
#include "Event_Listener.hpp"
#include "Event_Receivable.hpp"

namespace flgl
{

//Wrapper for queue and listener registration
class Event_Queue
{
private:
	//TODO use weak_ptr for this
	std::queue<Event> events;
	std::vector<std::weak_ptr<Event_Listener>> listeners;
public:
	//Default for -tors
	Event_Queue() = default;
	//Event_Queue is not copyable, but is move-constructable
	Event_Queue(const Event_Queue&) = delete;
	Event_Queue(Event_Queue&&) = default;

	//Add and remove functions
	void add_listener(std::shared_ptr<Event_Listener> listener_ptr);
	bool remove_listener(std::shared_ptr<Event_Listener> listener_ptr);

	//Push and pop Event
	void push_event(Event& e);
	Event pop_event();
	
	//Process event, running it through all listeners
	void process()
	{
		if (events.empty())
			return;
		
		//TODO substitute with std::for_each and a lambda
		//Pop events once
		for(auto it = listeners.begin(); it != listeners.end(); ++it)
		{
			Event e = events.front();
			
			if (auto ptr = it->lock())
				(ptr)->receive_event(e);
			else
				listeners.erase(it);
			
		}	
		
		events.pop();
	}
};

} //namespace flgl

#endif //FLEXIGLASS_EVENT_QUEUE_HPP
