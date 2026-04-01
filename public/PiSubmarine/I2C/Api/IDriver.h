#pragma once

#include <cstdint>

namespace PiSubmarine::I2C::Api
{
    class IDriver
    {
    public:
        virtual ~IDriver() = default;
        virtual bool Write(uint8_t deviceAddress, uint8_t* txData, size_t len) = 0;
        virtual bool Read(uint8_t deviceAddress, uint8_t* rxData, size_t len) = 0;
    };
}
