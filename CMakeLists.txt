cmake_minimum_required(VERSION 3.5)

project(cppinet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

add_executable(cppinet src/main.cpp src/port.cpp include/port.hpp src/host_info.cpp include/host_info.hpp include/dns.hpp src/dns.cpp include/address.hpp src/address.cpp include/cppinet_defines.hpp)
