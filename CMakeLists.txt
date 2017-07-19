project(rent)
set(CMAKE_CXX_FPAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
add_executable(rent driver.cpp rent.cpp)
