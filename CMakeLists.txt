cmake_minimum_required(VERSION 2.8.7)
project(bulletin_board C)

find_package(Doxygen)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wstrict-prototypes -pedantic")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -g -O0 -coverage")
set(CMAKE_EXE_LINKER_FLAGS="-coverage")

include_directories(lib/libsimple_message_client_commandline_handling)
include_directories(lib/simple_message_server_logic)

add_custom_target(
    libsimple_message_client_commandline_handling
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/libsimple_message_client_commandline_handling
)

add_custom_target(
    simple_message_server_logic
    COMMAND make
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/simple_message_server_logic
)

add_executable(simple_message_client src/simple_message_client.c)
add_executable(simple_message_server src/simple_message_server.c)

add_dependencies(simple_message_client libsimple_message_client_commandline_handling)
add_dependencies(simple_message_server simple_message_server_logic)

target_link_libraries(
    simple_message_client
    ${CMAKE_SOURCE_DIR}/lib/libsimple_message_client_commandline_handling/libsimple_message_client_commandline_handling.a
)

if(DOXYGEN_FOUND)
    add_custom_target(doc
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND ${DOXYGEN_EXECUTABLE})
endif()
