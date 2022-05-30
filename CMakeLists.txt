cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME statistic)
project(${PROJECT_NAME})

set( HEADERS statistic.h
             min.h
             max.h
             mean.h
             std_eval.h)

set( SOURCES main.cpp
             min.cpp
             max.cpp
             mean.cpp
            std_eval.cpp )

add_executable(${PROJECT_NAME} ${SOURCES}  ${HEADERS} )

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
