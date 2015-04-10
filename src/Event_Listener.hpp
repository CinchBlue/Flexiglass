#ifndef FLEXIGLASS_EVENT_LISTENER_HPP
#define FLEXIGLASS_EVENT_LISTENER_HPP

#include "common.hpp"
#include "Event.hpp"
#include "Event_Receivable.hpp"

namespace flgl
{
    namespace detail {
        //Void deleter which is necessary

        struct null_deleter
        {
            void operator() (void const* ) const {}
        };
    } //namespace detail

//Extendable, but basically passes an event along to the owner
class Event_Listener
{
public:
	Event_Listener(Event_Receivable& owner_obj)
	: 	owner(owner_obj)
	{
        //Need to initalize shared ptr to this after immediate construction
        //Otherwise, we get errors.
        this_ = create_this();
    }

    std::shared_ptr<Event_Listener> create_this()
    {
        std::shared_ptr<Event_Listener> px(this, flgl::detail::null_deleter());
        return px;
    }
	
	~Event_Listener() {};

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
