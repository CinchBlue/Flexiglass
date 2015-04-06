#ifndef FLEXIGLASS_EVENT_LISTENER_HPP
#define FLEXIGLASS_EVENT_LISTENER_HPP

#include "common.hpp"
#include "Event.hpp"
#include "Event_Receivable.hpp"

namespace flgl
{

//Extendable, but basically passes an event along to the owner
class Event_Listener
{
public:
	Event_Listener(Event_Receivable& owner_obj)
	: 	owner(owner_obj),
		this_(this)
	{}
	
	~Event_Listener() = default;

	//Overloadable to allow derived classes to do more logic here
	virtual void receive_event(Event& e) const
	{
		notify_owner(e);		
	}
	
	//Passes event to owner
	virtual void notify_owner(Event& e) const
	{
		owner.on_notify(e);
	}
	
	void set_owner(Event_Receivable& owner_obj) {owner = owner_obj;}
	
	std::shared_ptr<Event_Listener> get() {return this_;}

	Event_Receivable& get_owner_obj() {return owner;}
protected:
	//TODO integrate a weak_ptr here
	Event_Receivable& owner;
	std::shared_ptr<Event_Listener> this_; 
};

} //namespace flgl
#endif //FLEXIGLASS_EVENT_LISTENER_HPP
