cmake_minimum_required(VERSION 3.4)

project(Company VERSION 1.0 LANGUAGES CXX)

add_executable(Company main.cpp Company.cpp Department.cpp Department_ID.cpp Employee.cpp Employee_ID.cpp util.cpp)

install(TARGETS Company DESTINATION bin)
