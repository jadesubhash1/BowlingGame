cmake_minimum_required(VERSION 3.10)
project(BowlingGameProject)

set(CMAKE_CXX_STANDARD 17)

# Add GoogleTest
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# GTest executable (unit tests only)
add_executable(BowlingGameTests
    Tests/BowlingGameTests.cpp
    BowlingGame/BowlingGame.cpp
    BowlingGame/Frame.cpp
    BowlingGame/Player.cpp
)
target_link_libraries(BowlingGameTests gtest gtest_main pthread)

# Application executable (manual/hardcoded game)
add_executable(BowlingGameApp
    BowlingGame/main.cpp
    BowlingGame/BowlingGame.cpp
    BowlingGame/Frame.cpp
    BowlingGame/Player.cpp
)
