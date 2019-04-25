cmake_minimum_required(VERSION 3.7)
Project(MOHEngineTest)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Locate Sdl2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})



# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests EngineTest.cpp ../merry_our_hearts/MOHEngine.h)
target_link_libraries(executeTests ${GTEST_LIBRARIES} ${SDL2_LIBRARIES} pthread)
