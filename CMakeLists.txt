cmake_minimum_required(VERSION 3.6)
project(XeonWars)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Background.h Background.cpp MainSpaceShip.h MainSpaceShip.cpp enemy.h enemy.cpp  entity.h entity.cpp motion.h motion.cpp
     bullet.h bullet.cpp cannon.h cannon.cpp)
set(EXECUTABLE_NAME "XeonWars")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
#add_definitions(-DRES="Resources/")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
