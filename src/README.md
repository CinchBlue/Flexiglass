#Design of Flexiglass

Flexiglass is a experimental framework to integrate a generic programming mentality into an event-messaging framework.

##Release & Development

Flexiglass will maintain two branches of code: **release** and **master**.

* **Release** - Release will always have code 

##Dependencies

Dependencies will be controlled by having only one header for external dependencies: **common.hpp**. Across builds or branches, this means that changes to the external dependencies of Flexiglass can be easily found.

* C++ Standard Library
	* iostream
	* string
	* vector
	* queue
* Boost (1.57.0)
	* Boost.Any

