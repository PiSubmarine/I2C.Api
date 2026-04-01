#pragma once

#include <cstdint>
#include <functional>

namespace PiSubmarine::Api::Internal::I2C
{
	using Callback = std::function<void(uint8_t deviceAddress, bool)>;
}