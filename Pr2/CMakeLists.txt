cmake_minimum_required(VERSION 3.10)
project(MyUtility C)

set(CMAKE_C_STANDARD 11)

add_executable(my_utility main.c users.c processes.c help.c logger.c error_handler.c)
