cmake_minimum_required (VERSION 3.8)

project ("labyrinth-pathfinder")

# Leave next line, only in case you have SFML compiled for static linkage.
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5 REQUIRED graphics)

include_directories(${SFML_INCLUDE_DIR})
file(GLOB_RECURSE sources src/*.cpp src/*.h)
add_executable (labyrinth-pathfinder ${sources})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Roboto-Medium.ttf
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(labyrinth-pathfinder sfml-graphics)