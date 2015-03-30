#ifndef FLEXIGLASS_EVENT_LISTENER_HPP
#define FLEXIGLASS_EVENT_LISTENER_HPP

#include "common.hpp"
#include "Event.hpp"
#include "Event_Receivable.hpp"

namespace flgl
{

//Must be added to a class 
class Event_Listener
{
private:
	Event_Receivable* owner;
public:
	Event_Listener(Event_Receivable* owner_obj);
	~Event_Listener() = default;

	virtual void receive_event(Event* e) = 0;
	virtual void notify_owner(Event* e) = 0;
	void set_owner(Event_Receivable* owner_obj) {owner = owner_obj;}

	Event_Receivable* get_owner_obj() {return owner;}
};

} //namespace flgl
#endif //FLEXIGLASS_EVENT_LISTENER_HPP
