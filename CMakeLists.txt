cmake_minimum_required(VERSION 3.28)
project(fltk_test)

set(CMAKE_CXX_STANDARD 26)

find_package(FLTK REQUIRED NO_MODULE)
include_directories(${FLTK_INCLUDE_DIRS}) 
link_directories(${FLTK_LIBRARY_DIRS}) 
add_definitions(${FLTK_DEFINITIONS})

add_executable(fltk_test 
    main.cpp

    misc/graph.cpp
    misc/gui.cpp
    misc/window.cpp
)

target_link_libraries(fltk_test fltk)
