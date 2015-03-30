#Flexiglass
Flexiglass is a generic event system with a very light footprint. With just the C++ Standard Library and Boost.Any, this little event system can help you with probably nothing, as you can probably just roll one more expansive and better-performing than this one.

Flexiglass is just an educational experiment. The library currently is suited towards Windows, and uses only MinGW-w64 to compile. Be sure to use C++11.

##Building Flexiglass

Building Flexiglass is quite easy. It has only 10 source files. The Makefile in the top directory is set to build a static library of Flexiglass. However, there are a few dependencies:

* Boost.Any (Boost version 1.57.0)

And that's it. The Makefile is set to look for Boost in a directory called "dependencies/boost", so just download the latest version of Boost that is still compatible with Boost.Any, place it under dependencies, and then rename the folder to Boost.

On Windows, if you use MinGW-w64 you need only use these commands:

	mingw32-make windows_clean
	mingw32-make window_prep
	mingw32-make

These will help you build and rebuild Flexiglass as needed. If you have a better build system, by all means, just plug the 10 source files in.

If you use Linux, it's not too hard to create another makefile that does the same things as Windows.

##Using Flexiglass

Flexiglass depends on Boost.Any, which means that you must provide Boost.Any and any of its dependencies for the library.

I don't like this.

Then, all you have to do is

	include "Flexiglass.hpp"

and make sure to add a -I and and -L for both the directories for the header file and the static library.
