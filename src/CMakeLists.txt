include("${PISUBMARINE_BUILD_SYSTEM}")

add_library(PiSubmarine.I2C.Api INTERFACE
        ../public/PiSubmarine/I2C/Api/IDriver.h
        ../public/PiSubmarine/I2C/Api/IDriverAsync.h
        ../public/PiSubmarine/I2C/Api/DriverConcept.h
        ../public/PiSubmarine/I2C/Api/DriverAsyncConcept.h
        ../public/PiSubmarine/I2C/Api/Callback.h
)
target_include_directories(PiSubmarine.I2C.Api INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/../public")
PiSubmarineInitTarget(PiSubmarine.I2C.Api)