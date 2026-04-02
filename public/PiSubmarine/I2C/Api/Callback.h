#pragma once

#include <cstdint>
#include <functional>

namespace PiSubmarine::I2C::Api
{
	using Callback = std::function<void(uint8_t deviceAddress, bool)>;
}