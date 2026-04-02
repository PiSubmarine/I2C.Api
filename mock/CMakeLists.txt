message("${_build_cmake_local}")
include("${_build_cmake_local}")

add_library(PiSubmarine.I2C.Api.Mock INTERFACE
        PiSubmarine/I2C/Api/IDriverMock.h
)
target_include_directories(PiSubmarine.I2C.Api.Mock INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
PiSubmarineInitTarget(PiSubmarine.I2C.Api.Mock)

find_package(GTest)
target_link_libraries(PiSubmarine.I2C.Api.Mock INTERFACE GTest::gtest_main GTest::gmock_main)