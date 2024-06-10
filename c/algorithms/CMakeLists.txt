# CMakeList.txt : CMake project for DataStructures, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("algorithms")

# Add source to this project's executable.
add_executable (algorithms "main.c algorithms.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DataStructures PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
8