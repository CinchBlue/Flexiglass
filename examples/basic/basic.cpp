#include <iostream>
#include "Flexiglass.hpp"

int main()
{
	//Events in Flexiglass can only be created
	//with its name and type provided as strings
	flgl::Event* e = new flgl::Event("Event", "Text");
	std::string str = "Hello World!";
	std::string str2 = "This is the second insertion into the list.";
	
	//Add info onto the queue.
	//Order does matter. First in is first out (FIFO)
	e->push_data(str);
	e->push_data(str2);
	
	//Create an event queue
	flgl::Event_Queue q;
	
	//Push the event onto the event queue
	q.push_event(*e);

	delete e;
	
	//Pop the front of the queue, receive the event
	flgl::Event received = q.pop_event();
	
	//Unpack the type and the name.
	std::cout << received.get_name() << std::endl;
	std::cout << received.get_type() << std::endl;
	
	//Retrieve the list of data from the event
	flgl::info_list event_data = received.get_data();
	
	//Start popping from the front
	for (auto it : event_data)
	{
		//Use a template to unpack your data how you see fit.
		std::cout << flgl::unpack<std::string>(it) << std::endl;
	}

	return 0;
}