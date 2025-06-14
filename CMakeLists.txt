cmake_minimum_required(VERSION 3.10)
project(BowlingGameTests)

set(CMAKE_CXX_STANDARD 17)

# Add GoogleTest
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Add source files
add_executable(BowlingGameTests
    Tests/BowlingGameTests.cpp
    BowlingGame/BowlingGame.cpp
    BowlingGame/Frame.cpp
    BowlingGame/Player.cpp
)

# Link GTest
target_link_libraries(BowlingGameTests gtest gtest_main pthread)
