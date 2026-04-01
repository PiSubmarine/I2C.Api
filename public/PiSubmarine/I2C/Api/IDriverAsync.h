#pragma once

#include <cstdint>
#include "PiSubmarine/I2C/Api/Callback.h"

namespace PiSubmarine::I2C::Api
{
    class IDriverAsync
    {
    public:
        virtual ~IDriverAsync() = default;
        virtual bool WriteAsync(uint8_t deviceAddress, uint8_t* txData, size_t len, PiSubmarine::Api::Internal::I2C::Callback callback) = 0;
        virtual bool ReadAsync(uint8_t deviceAddress, uint8_t* rxData, size_t len, PiSubmarine::Api::Internal::I2C::Callback callback) = 0;
    };
}
