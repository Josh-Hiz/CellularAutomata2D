cmake_minimum_required(VERSION 3.23)
project(CellularAutomata2D)
set(CMAKE_CXX_STANDARD 20)

message(STATUS "start running cmake...")

find_package(Boost 1.79.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

endif()

add_executable(CellularAutomata2D main.cpp GridManager/Grid.cpp GridManager/Grid.h GridManager/Nodes.cpp GridManager/Nodes.h)

include_directories(/opt/homebrew/Cellar)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(CellularAutomata2D sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

if(Boost_FOUND)

    target_link_libraries(CellularAutomata2D ${Boost_LIBRARIES})

endif()