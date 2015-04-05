#ifndef FLEXIGLASS_EVENT_RECEIVABLE_HPP
#define FLEXIGLASS_EVENT_RECEIVABLE_HPP

#include "common.hpp"
#include "Event.hpp"

namespace flgl
{

//A simple interface for allowing objects to
//handle events in a uniform way
//Pure virtual class
class Event_Receivable
{
public:
	virtual ~Event_Receivable() {}
	virtual void on_notify(Event* e) = 0;

};


} //namespace flgl

#endif //FLEXIGLASS_EVENT_RECEIVABLE_HPP
