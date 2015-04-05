#include "Event_Sender.hpp"

namespace flgl
{
	
Event_Sender::Event_Sender(Event_Queue& e_queue)
: 	event_queue(&e_queue)
{}

void Event_Sender::send_event(Event& e)
{
	event_queue->push_event(e);
}

void Event_Sender::send_event(Event& e, Event_Queue& q)
{
	q.push_event(e);
}
	
}//namespace flgl

