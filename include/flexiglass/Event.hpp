#ifndef FLEXIGLASS_EVENT_HPP
#define FLEXIGLASS_EVENT_HPP

#include "common.hpp"

namespace flgl
{
	
typedef std::list<boost::any> info_list;

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
private:
	std::string name;
	std::string type;
	std::list<boost::any> info;
public:
	//Constructor
	//Events can only be constructed with the strings provided
	Event(const std::string& name_str, const std::string& type_str)
	{
		name = name_str;
		type = type_str;
	}
	
	//Destructor
	~Event() = default;
	
	//Copy and move
	void attach_data(boost::any& data) {info.push_back(data);}
	void attach_data(boost::any&& data) {info.emplace_back(data);}
	
	//Assignment
	void operator=(Event& other)
	{
		name = other.name;
		type = other.type;
		info = other.info;
	}

	//Set
	void set_name(const std::string& str) {name = str;}
	void set_type(const std::string& str) {type = str;}
	template <class T> void push_info(T& i)
	{
		boost::any package = i;
		info.push_back(package);
	}
		
	//Get
	std::string& get_name() {return name;}
	std::string& get_type() {return type;}
	std::list<boost::any>& get_info() {return info;}
	
	//Clear
	void clear_info() {info.clear();}
};

//Used to extract info from boost_any objects.
//A light wrapper
template <class T>
T unpack(boost::any b)
{
	return boost::any_cast<T>(b);
}

} //namespace flgl
#endif //FLEXIGLASS_EVENT_HPP