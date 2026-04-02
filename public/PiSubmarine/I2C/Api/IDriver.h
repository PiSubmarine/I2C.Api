#pragma once

#include <cstdint>
#include <cstddef>

namespace PiSubmarine::I2C::Api
{
    class IDriver
    {
    public:
        virtual ~IDriver() = default;
        virtual bool Write(uint8_t deviceAddress, uint8_t* txData, std::size_t len) = 0;
        virtual bool Read(uint8_t deviceAddress, uint8_t* rxData, std::size_t len) = 0;
    };
}
