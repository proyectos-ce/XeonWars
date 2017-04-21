cmake_minimum_required(VERSION 3.5C)
project(XeonWars)

set(CMAKE_CXX_STANDARD 14)


set(SOURCE_FILES main.cpp Background.h Background.cpp MainSpaceShip.h MainSpaceShip.cpp List.h Node.h List.cpp Node.cpp Game.h Game.cpp Collision.cpp Collision.h Queue.cpp Queue.h Screen.h Screens.h Menu.cpp Menu.h Utils.cpp Utils.h powerUp.h enemy.h enemy.cpp  entity.h entity.cpp motion.h motion.cpp
     bullet.h bullet.cpp cannon.h cannon.cpp collisionmanager.h collisionmanager.cpp ConnectionManager.cpp ConnectionManager.h ScoreManager.cpp ScoreManager.h BossManager.cpp BossManager.h GameOverScreen.cpp GameOverScreen.h)

set(EXECUTABLE_NAME "XeonWars")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

SET(GCC_COVERAGE_LINK_FLAGS "-lmosquitto")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

#add_definitions(-DRES="Resources/")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
find_package(Mosquitto REQUIRED)
if(SFML_FOUND AND MOSQUITTO_FOUND)
    include_directories(${SFML_INCLUDE_DIR} ${MOSQUITTO_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${MOSQUITTO_LIBRARIES})
endif()
