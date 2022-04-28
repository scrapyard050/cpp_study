cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME scores)
project(${PROJECT_NAME})

set(HEADERS prepare.h
            table.h
            play.h)

set(SOURCES main.cpp
            prepare.cpp
            table.cpp
            play.cpp )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} )

set_target_properties(scores PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
