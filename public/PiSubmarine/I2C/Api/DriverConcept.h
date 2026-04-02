#pragma once

#include "PiSubmarine/I2C/Api/Callback.h"
#include <cstdint>
#include <cstddef>

namespace PiSubmarine::I2C::Api
{
	template<typename T>
	concept DriverConcept = requires(T driver, uint8_t deviceAddress, uint8_t * txData, uint8_t * rxData, std::size_t len)
	{
		{ driver.Write(deviceAddress, txData, len) } -> std::same_as<bool>;
		{ driver.Read(deviceAddress, rxData, len) } -> std::same_as<bool>;
	};

}