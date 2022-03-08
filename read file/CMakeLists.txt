cmake_minimum_required(VERSION 3.20)
project(c___review)

set(CMAKE_CXX_STANDARD 14)

add_executable(c___review
        "text_file_reading.cpp" "../date class/driver.cpp" "../date class/date.h" "../circlar sorted linked list/circular_sorted_linked_list.h" "../circlar sorted linked list/circular_sorted_linked_list.cpp" "../circlar sorted linked list/main.cpp")
