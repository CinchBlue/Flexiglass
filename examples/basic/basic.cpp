#include <iostream>
#include "Flexiglass.hpp"
#include <typeinfo>
#include <chrono>

int main()
{
	//Events in Flexiglass can only be created
	//with its name and type provided as strings
	flgl::Event e("event_type", "event_name");
	std::string str = "Hello World!";
	std::string str2 = "2nd insertion";
	
	//Add info onto the queue.
	//Order does matter. First in is first out (FIFO)
	e.push_data(str);
	e.push_data(str2);
	
	//You can also choose to create a flgl::any object
	//to attach data to.
	flgl::any any_str3 = int(1098);
	
	//attach_data(flgl::any) will attach data to the end
	e.attach_data(any_str3);
	
	//Create an event queue
	flgl::Event_Queue q;
	
	//Push the event onto the event queue
	q.push_event(e);

	//Pop the front of the queue, receive the event
	flgl::Event received = q.pop_event();
	
	//Unpack the type and the name.
	//The name and type can also be used as metadata
	//This is convenient for peeking at the type of the object
	//without having to use a cast mechanism
	std::cout << received.get_type() << std::endl;
	std::cout << received.get_name() << std::endl;

	
	//Retrieve the list of data from the event
	flgl::data_list event_data = received.get_data();
	
	//Start popping from the front
	try
	{
		for (auto it : event_data)
		{
			//Use a template to unpack your data how you see fit.
			//If it fails, the function will throw an exception
			std::cout << flgl::unpack<std::string>(it) << std::endl;
		}
	}
	//Should happen on third cast
	//Let's catch an exception of the std::bad_cast
	catch(std::bad_cast& ex)
	{
		std::cout << "Bad cast from int to std::string! " << ex.what() << std::endl;
	}
	
	return 0;
}