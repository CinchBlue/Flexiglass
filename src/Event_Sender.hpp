#ifndef FLEXIGLASS_EVENT_SENDER_HPP
#define FLEXIGLASS_EVENT_SENDER_HPP

#include "Event.hpp"
#include "Event_Queue.hpp"

namespace flgl
{

//A simple class for firing off events to an Event_Queue
//Note that the Evene_Queue is not set by default, and must
//always be set.
class Event_Sender
{
public:
	//Constructor
	//Must always provide a target queue
	Event_Sender(Event_Queue& e_queue);
	
	//Send to default or targeted queue
	void send_event(Event& e);
	void send_event(Event& e, Event_Queue& q);

	//Set event queue
	void set_event_queue(Event_Queue& e_queue) {event_queue = &e_queue;}

	Event_Queue* get_event_queue() {return event_queue;}

private:
	Event_Queue* event_queue;
};

} //namespace flgl

#endif //FLEXIGLASS_EVENT_SENDER_HPP
