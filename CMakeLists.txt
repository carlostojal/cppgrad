cmake_minimum_required(VERSION 3.11)
project(cppgrad VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CPPGRAD_SOURCES
	src/node.cpp
	#src/linalg/matrix.cpp
	src/linalg/tensor.cpp
	src/operators/op.cpp
	src/operators/mul.cpp
)

add_library(cppgrad SHARED ${CPPGRAD_SOURCES})

target_include_directories(cppgrad PUBLIC include)

#add_executable(test_matrix tests/test_matrix.cpp)
#target_link_libraries(test_matrix PUBLIC cppgrad)
