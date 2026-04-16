#pragma once

#include "PiSubmarine/Error/Api/Result.h"

#include <cstdint>
#include <span>

namespace PiSubmarine::I2C::Api
{
    template<typename T>
    concept DriverConcept = requires(T driver, uint8_t deviceAddress)
    {
        { driver.Write(deviceAddress, std::span<const uint8_t>{}) } -> std::same_as<PiSubmarine::Error::Api::Result<void>>;
        { driver.Read(deviceAddress, std::span<uint8_t>{}) } -> std::same_as<PiSubmarine::Error::Api::Result<void>>;
        { driver.WriteRead(deviceAddress, std::span<const uint8_t>{}, std::span<uint8_t>{}) } -> std::same_as<PiSubmarine::Error::Api::Result<void>>;
    };
}
