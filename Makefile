CXX = g++
CXXFLAGS = -pipe -O2 -std=c++11 -Wall -Wextra -pedantic

SRC := $(wildcard src/*.cpp)
OBJ := $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))

obj/%.o : src/%.cpp
	$(CXX) -Isrc -c $< -o $@ $(CXXFLAGS) 

lib/libflexiglass.a: $(OBJ) $(SRC)
	ar rcs lib/libflexiglass.a $(OBJ)
	
windows_clean:
	rmdir obj /s
	
windows_prep:
	mkdir obj