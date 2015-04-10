#ifndef FLEXIGLASS_EVENT_HPP
#define FLEXIGLASS_EVENT_HPP

#include "common.hpp"
#include "any.hpp"

namespace flgl
{

//
typedef std::deque<flgl::any> data_list;

/*
 * Event is used extensively within the program.
 * It is the basis for all messages in the event system.
 * Objects will send and receive events.
 *
 * It uses boost::any in order to be able to
 * attach any kind of data to be read.
 */
class Event
{
public:
	//Constructor
	//Events can only be constructed with the strings provided
	Event(const std::string& type_str, const std::string& name_str)
	:	type(type_str),
		name(name_str)
	{}
	
	//Destructor
	~Event() = default;
	
	//Copy constructor
	Event(const Event& other)
	: 	type(other.type),
		name(other.name),
		data(other.data)
	{}
	
	//Copy assignment
	Event& operator=(const Event& other)
	{
		if (this != &other)
		{
			type = other.type;
			name = other.name;
			data = other.data;
		}
		return *this;
	}
	
	//Move constructor
	Event(Event&& other)
	: 	type(std::move(other.type)),
		name(std::move(other.name)),
		data(std::move(other.data))
	{}
	
	//Move assignment
	Event& operator=(Event&& other)
	{
		std::swap(*this, other);
		return *this;
	}
	
	//Copy and move data
	void attach_data(flgl::any& a) {data.push_back(a);}
	void attach_data(flgl::any&& a) {data.emplace_back(a);}

	
	//Pushing data
	template <class T> void push_data(T i)
	{
		flgl::any package = i;
		data.push_back(package);
	}

	//Set
	void set_name(const std::string& str) {name = str;}
	void set_type(const std::string& str) {type = str;}
		
	//Get
	std::string get_name() const {return name;}
	std::string get_type() const {return type;}
	flgl::data_list get_data() const {return data;}
	
	//Clear
	void clear_data() {data.clear();}
private:
	std::string type;
	std::string name;
	std::deque<flgl::any> data;
};

//Used to extract data from boost_any objects.
//A light wrapper
template <class T>
T unpack(flgl::any a)
{
	return flgl::any_cast<T>(a);
}

} //namespace flgl

#endif //FLEXIGLASS_EVENT_HPP