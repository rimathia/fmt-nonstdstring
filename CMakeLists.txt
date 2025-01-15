cmake_minimum_required(VERSION 3.5...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(thirdpartystring
        VERSION 0.1
        DESCRIPTION "example for using fmt with a custom string"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(fmt)
add_subdirectory(nonstdstring)
add_subdirectory(test_nonstdstring)
