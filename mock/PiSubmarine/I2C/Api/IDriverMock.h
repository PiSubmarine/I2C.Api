#pragma once

#include <cstdint>
#include <span>
#include <gmock/gmock.h>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/I2C/Api/IDriver.h"

namespace PiSubmarine::I2C::Api
{
    class IDriverMock : public IDriver
    {
    public:
        MOCK_METHOD((PiSubmarine::Error::Api::Result<void>), Write, (uint8_t deviceAddress, std::span<const uint8_t> txData), (override));
        MOCK_METHOD((PiSubmarine::Error::Api::Result<void>), Read, (uint8_t deviceAddress, std::span<uint8_t> rxData), (override));
        MOCK_METHOD((PiSubmarine::Error::Api::Result<void>), WriteRead, (uint8_t deviceAddress, std::span<const uint8_t> txData, std::span<uint8_t> rxData), (override));
    };
}
