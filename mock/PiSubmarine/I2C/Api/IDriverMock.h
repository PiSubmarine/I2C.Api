#pragma once

#include <cstddef>
#include <cstdint>
#include <gmock/gmock.h>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/I2C/Api/IDriver.h"

namespace PiSubmarine::I2C::Api
{
    class IDriverMock : public IDriver
    {
    public:
        MOCK_METHOD((PiSubmarine::Error::Api::Result<void>), Write, (uint8_t deviceAddress, uint8_t* txData, std::size_t len), (override));
        MOCK_METHOD((PiSubmarine::Error::Api::Result<void>), Read, (uint8_t deviceAddress, uint8_t* rxData, std::size_t len), (override));
        MOCK_METHOD((PiSubmarine::Error::Api::Result<void>), WriteRead, (uint8_t deviceAddress, uint8_t* txData, std::size_t txLen, uint8_t* rxData, std::size_t rxLen), (override));
    };
}
