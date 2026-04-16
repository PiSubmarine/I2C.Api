#pragma once

#include <cstddef>
#include <cstdint>
#include <span>

#include "PiSubmarine/Error/Api/Result.h"

namespace PiSubmarine::I2C::Api
{
    class IDriver
    {
    public:
        virtual ~IDriver() = default;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<void> Write(
            uint8_t deviceAddress,
            std::span<const uint8_t> txData) = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<void> Read(
            uint8_t deviceAddress,
            std::span<uint8_t> rxData) = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<void> WriteRead(
            uint8_t deviceAddress,
            std::span<const uint8_t> txData,
            std::span<uint8_t> rxData) = 0;
    };
}
