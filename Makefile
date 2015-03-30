CXX = g++
CXXFLAGS = -pipe -std=c++11 -Wall -Wextra -pedantic

BOOST_INCLUDE = dependencies/boost

SRC := $(wildcard src/*.cpp)
OBJ := $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))

obj/%.o : src/%.cpp
	$(CXX) -I$(BOOST_INCLUDE) -Isrc -c $< -o $@ $(CXXFLAGS) 

lib/libflexiglass.a: $(OBJ) $(SRC)
	ar rcs lib/libflexiglass.a $(OBJ)
	
windows_clean:
	rmdir obj /s
	
windows_prep:
	mkdir obj