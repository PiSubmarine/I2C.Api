cmake_minimum_required(VERSION 3.20)

include(FetchContent)

project(PiSubmarine.I2C.Api.Test LANGUAGES CXX)

set(PiSubmarine.I2C.Api.Test.Sources
        "PiSubmarine/I2C/Api/IDriverTest.cpp")

enable_testing()

# spdlog
find_package(spdlog)
find_package(GTest)

add_executable(PiSubmarine.I2C.Api.Test ${PiSubmarine.I2C.Api.Test.Sources})
PiSubmarineInitTarget(PiSubmarine.I2C.Api.Test)

target_link_libraries(PiSubmarine.I2C.Api.Test PRIVATE PiSubmarine.I2C.Api)
target_link_libraries(PiSubmarine.I2C.Api.Test PRIVATE spdlog::spdlog)
target_link_libraries(PiSubmarine.I2C.Api.Test PRIVATE GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(PiSubmarine.I2C.Api.Test)