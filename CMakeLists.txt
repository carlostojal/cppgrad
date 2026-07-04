cmake_minimum_required(VERSION 3.11)
project(cppgrad VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 17)

set(CPPGRAD_SOURCES
	src/linalg/matrix.cpp
)

if(BUILD_SHARED_LIBS)
	add_library(cppgrad SHARED ${CPPGRAD_SOURCES})
else()
	add_library(cppgrad STATIC ${CPPGRAD_SOURCES})
endif()

target_include_directories(cppgrad PUBLIC include)
