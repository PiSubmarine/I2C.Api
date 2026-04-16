#pragma once

#include "PiSubmarine/Error/Api/Result.h"

#include <cstdint>
#include <cstddef>

namespace PiSubmarine::I2C::Api
{
	template<typename T>
	concept DriverConcept = requires(T driver, uint8_t deviceAddress, uint8_t * txData, uint8_t * rxData, std::size_t len)
	{
		{ driver.Write(deviceAddress, txData, len) } -> std::same_as<PiSubmarine::Error::Api::Result<void>>;
		{ driver.Read(deviceAddress, rxData, len) } -> std::same_as<PiSubmarine::Error::Api::Result<void>>;
		{ driver.WriteRead(deviceAddress, txData, len, rxData, len) } -> std::same_as<PiSubmarine::Error::Api::Result<void>>;
	};
}
