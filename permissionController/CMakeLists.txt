cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_FIND_LIBRARY_PREFIXES "lib")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".so;.a")
# Search OpenSSL

find_package(OpenSSL REQUIRED)


set(sourceFile check.cpp checkPermission.h checkPermission.cpp)
add_library(checker ${sourceFile})
# add_executable(${PROJECT_NAME} ${sourceFile})
target_link_libraries(checker OpenSSL::Crypto)