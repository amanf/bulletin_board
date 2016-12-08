cmake_minimum_required(VERSION 2.8.7)
project(bulletin_board C)

find_package(Doxygen)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wstrict-prototypes -pedantic")

add_executable(simple_message_client src/simple_message_client.c)
add_executable(simple_message_server src/simple_message_server.c)

if(DOXYGEN_FOUND)
    add_custom_target(doc
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMAND ${DOXYGEN_EXECUTABLE})
endif()