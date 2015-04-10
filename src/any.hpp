#ifndef FLEXIGLASS_ANY_HPP
#define FLEXIGLASS_ANY_HPP

//Credit to sehe, user of Stack Overflow
//Code has been modified from example

#include <memory>
#include <stdexcept>

namespace flgl
{
	
class any
{
public:
	//Keep the default constructor
    any() = default;
	
	//Templated initialization
    template <typename T>
	any(const T& v)
	: data(new storage<T>(v))
	{ }
	
	//Copy constructor, move a clone of other data or keep a nullptr if empty
    any(const any& other)
	: data(other.data ? std::move(other.data->clone()) : nullptr)
	{}

	//Swap
    void swap(any& other)
	{
		data.swap(other.data);
	}
	
	//Global wrapper for swap method

	
	//Assignment
    any& operator=(any other)
	{
		swap(other);
		return *this;
	}

    //Move semantics to be implemented later
private:

	//Virtual interface for storage
    struct storage_base { 
        virtual std::unique_ptr<storage_base> clone() = 0;
        virtual ~storage_base() = default; 
    };
	
	//Templated storage unit
    template <typename T>
    struct storage : storage_base {
		//The actual value
        T value;
		
		//Value constructor
        explicit storage(const T& v)
		: value(v)
		{}
		
		//Return a clone of internals
        std::unique_ptr<storage_base> clone()
		{
			return std::unique_ptr<storage_base>(new storage<T>(value));
		}
		
    };
	
	//Private members
    std::unique_ptr<storage_base> data;
	
	//friends
    template<typename T>
	friend T& any_cast(any&);
	
    template<typename T>
	friend T const& any_cast(const any&);
	
	friend void swap(flgl::any& a, flgl::any& b)
	{
		a.swap(b);
	}
};

template <typename T>
T& any_cast(any& a)
{ 
    if (auto p = dynamic_cast<any::storage<T>*>(a.data.get()))
        return p->value;
    else
        throw std::bad_cast();
}

template <typename T>
T const& any_cast(const any& a)
{ 
    if (auto p = dynamic_cast<any::storage<T> const*>(a.data.get()))
        return p->value;
    else
        throw std::bad_cast();
	
	
}

}





#endif //FLEXIGLASS_ANY_HPP