cmake_minimum_required (VERSION 3.8)

project ("labirint-pathfinder")

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 REQUIRED graphics)

include_directories(${SFML_INCLUDE_DIR})
add_executable (labirint-pathfinder "src/main.cpp" "src/GraphNode.h" "src/calculateCosts.h" "src/calculateCosts.cpp" "src/PathfinderGUI.h" "src/buildPath.h" "src/buildPath.cpp")

target_link_libraries(labirint-pathfinder sfml-graphics)