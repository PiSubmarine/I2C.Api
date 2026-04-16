#pragma once

#include <cstdint>
#include <cstddef>

#include "PiSubmarine/Error/Api/Result.h"

namespace PiSubmarine::I2C::Api
{
    class IDriver
    {
    public:
        virtual ~IDriver() = default;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<void> Write(
            uint8_t deviceAddress,
            uint8_t* txData,
            std::size_t len) = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<void> Read(
            uint8_t deviceAddress,
            uint8_t* rxData,
            std::size_t len) = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<void> WriteRead(
            uint8_t deviceAddress,
            uint8_t* txData,
            std::size_t txLen,
            uint8_t* rxData,
            std::size_t rxLen) = 0;
    };
}
