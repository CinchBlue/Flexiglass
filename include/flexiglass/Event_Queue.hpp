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
	std::queue<Event> events;
	std::vector<Event_Listener*> listeners;
public:
	//Default for -tors

	//Add and remove functions
	void add_receiver(Event_Listener* listener_ptr);
	bool remove_receiver(Event_Listener* listener_ptr);

	//Push and pop Event
	void push_event(Event& e);
	Event pop_event();
};

} //namespace flgl

#endif //FLEXIGLASS_EVENT_QUEUE_HPP
