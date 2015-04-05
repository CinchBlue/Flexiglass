#Flexiglass
Flexiglass is a generic event system with a very light footprint. With just the C++ Standard Library, this little event system can help you with probably nothing, as you can probably just roll one more expansive and better-performing than this one.

Flexiglass is just an educational experiment. The library currently is suited towards Windows, and uses only MinGW-w64 to compile. Be sure to use C++11.

##Building Flexiglass

Building Flexiglass is easy. The Makefile in the top directory is set to build a static library of Flexiglass for Windows 8.1, but should be very easily adjusted for Linux.

On Windows, if you use MinGW-w64 you need only use these commands:

	mingw32-make windows_clean
	mingw32-make window_prep
	mingw32-make

These will help you build and rebuild Flexiglass as needed. If you have a better build system, by all means, just plug the source files in.

##Using Flexiglass

Flexiglass implements a basic event-handling framework. It has an **Event\_Queue** class for notifying **Event\_Listener** objects and holding **Event** objects. It also features a basic **Event\_Receivable** interface to be inherited from. Finally, it also has a basic **Event\_Sender** object to serve as a nice package to tack onto a class in the case that they also want to fire off events.

	#include "Flexiglass.hpp"

and make sure to add a -I and and -L for both the directories for the header file and the static library.
