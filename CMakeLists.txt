cmake_minimum_required(VERSION 2.8)

project(flexiglass)

set (CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -pedantic")
set (CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

install(DIRECTORY DESTINATION bin)
#add_subdirectory(bin)

set (EXECUTABLE_OUTPUT_PATH $(PROJECT_BINARY_DIR)/bin)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(flexiglass STATIC src/Event_Sender.cpp src/Event_Queue.cpp src/Event_Listener.cpp)


