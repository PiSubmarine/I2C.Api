#pragma once

#include <cstdint>
#include <cstddef>
#include "PiSubmarine/I2C/Api/Callback.h"

namespace PiSubmarine::I2C::Api
{
    class IDriverAsync
    {
    public:
        virtual ~IDriverAsync() = default;
        virtual bool WriteAsync(uint8_t deviceAddress, uint8_t* txData, std::size_t len, Callback callback) = 0;
        virtual bool ReadAsync(uint8_t deviceAddress, uint8_t* rxData, std::size_t len, Callback callback) = 0;
    };
}
