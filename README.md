#Flexiglass
Flexiglass is a generic event system framework with a very light footprint. With just the C++ Standard Library, this little event system can help you with probably nothing, as you can probably just roll one more expansive and better-performing than this one.

Flexiglass is just an educational experiment. The library currently is suited towards Windows, and uses only MinGW-w64 to compile. Be sure to use C++11.

##Building Flexiglass

Building Flexiglass is easy. The Makefile in the top directory is set to build a static library of Flexiglass for Windows 8.1, but should be very easily adjusted for Linux.
**
On Windows, if you use MinGW-w64 you need only use these commands:**

	mingw32-make c
	mingw32-make p
	mingw32-make

These will help you build and rebuild Flexiglass as needed. If you have a better build system, by all means, just plug the source files in.

**The makefile should build the static library within the /lib directory.** If it cannot build, be sure that the /lib and /obj directories are empty.

###Examples

All Flexiglass examples are set to be compiled out of the box with a simple "make" or "mingw32-make" command, with no parameters or settings required except that the library be built before hand.

##Using Flexiglass

Flexiglass (**namespace flgl**) implements a basic event-handling framework. It has an **Event\_Queue** class for notifying **Event\_Listener** objects and holding **Event** objects. It also features a basic **Event\_Receivable** interface (consisting of only on_notify) to be inherited from. Finally, it also has a basic **Event\_Sender** object to serve as an easy-to-add hub for sending events onto an Event\_Queue object.

To use Flexiglass, it requires the inclusion of a great amount of headers--one:

	#include "Flexiglass.hpp"

and make sure to add a -I and and -L for both the directories for the header file and the static library.


