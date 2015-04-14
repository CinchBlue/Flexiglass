#Flexiglass
Flexiglass is a generic event system framework with a very light footprint. With just the C++ Standard Library, this little event system can help you with probably nothing, as you can probably just roll one more expansive and better-performing than this one.

Flexiglass is just an educational experiment. Be sure to use a C++11 compiler.

##Building Flexiglass

Building Flexiglass is easy. If you use CMake (minimum version 2.8) at the command line with GNU Make, use the following commands:

	cmake -G"Unix Makefiles" (OR MinGW Makefiles for MinGW)
	make (OR mingw32-make for MinGW)

If you need to rebuild, simply remove the CMake directories and files besides CMakeLists.txt. If you have a better build system, by all means, just plug the source files in.

**The makefile should build the static library within the /bin directory.** If it cannot build, be sure that the /lib and /obj directories are empty.

**Make sure you move the static library from /bin to /lib.** This is required to build the examples, which already have pre-made makefiles.

###Examples

All Flexiglass examples are set to be compiled out of the box with a simple "make" or "mingw32-make" command, with no parameters or settings required except that the library be built before hand and put into the /lib directory.

##Using Flexiglass

Flexiglass (**namespace flgl**) implements a basic event-handling framework. It has an **Event\_Queue** class for notifying **Event\_Listener** objects and holding **Event** objects. It also features a basic **Event\_Receivable** interface (consisting of only on_notify) to be inherited from. Finally, it also has a basic **Event\_Sender** object to serve as an easy-to-add hub for sending events onto an Event\_Queue object.

To use Flexiglass, it requires the inclusion of a great number of headers--one:

	#include "Flexiglass.hpp"

and make sure to add the directories for the the header file and the static library to your build configuration.


