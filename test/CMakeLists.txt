cmake_minimum_required(VERSION 3.7)
project(test)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# locate SDL
find_package(SDL2 REQUIRED)
include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests EngineTest.cpp ../core/MOHSprites.cpp )
target_link_libraries(runTests ${GTEST_LIBRARIES} ${SDL2_LIBRARIES} pthread)
