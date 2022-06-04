cmake_minimum_required(VERSION 3.15)
project(containerts)
set(HEADERS my_vector.h
            my_list.h
)

set(SOURCES main.cpp )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} )

set_target_properties(scores PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
