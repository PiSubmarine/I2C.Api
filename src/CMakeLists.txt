include("${PISUBMARINE_BUILD_SYSTEM}")

add_library(PiSubmarine.I2C.Api INTERFACE
        ../public/PiSubmarine/I2C/Api/IDriver.h
        ../public/PiSubmarine/I2C/Api/DriverConcept.h
)
target_include_directories(PiSubmarine.I2C.Api INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/../public")
PiSubmarineInitTarget(PiSubmarine.I2C.Api)

PiSubmarineAddDependency("https://github.com/PiSubmarine/Error.Api.git" "")
target_link_libraries(PiSubmarine.I2C.Api INTERFACE PiSubmarine.Error.Api)
