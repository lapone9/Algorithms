cmake_minimum_required(VERSION 3.10)

project (linked_list)

add_library(linked_list linked_list.c)

set(CMAKE_BUILD_TYPE Debug)

add_executable(linked_list_test linked_list_unit_test.c)
target_link_libraries(linked_list_test linked_list)

ENABLE_TESTING()
ADD_TEST(UnitTests linked_list_test)
