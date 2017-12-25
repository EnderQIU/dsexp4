cmake_minimum_required(VERSION 3.8)
project(dsexp4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp stusys.cpp stusys.h student.cpp student.h HashTable.cpp HashTable.h)
add_executable(dsexp4 ${SOURCE_FILES})