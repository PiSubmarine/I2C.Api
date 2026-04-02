#pragma once

#include "PiSubmarine/I2C/Api/Callback.h"

namespace PiSubmarine::I2C::Api
{
	template<typename T>
	concept DriverAsyncConcept = requires(T driver, uint8_t deviceAddress, uint8_t * txData, uint8_t * rxData, size_t len, Callback callback)
	{
		{ driver.WriteAsync(deviceAddress, txData, len, callback) } -> std::same_as<bool>;
		{ driver.ReadAsync(deviceAddress, rxData, len, callback) } -> std::same_as<bool>;
	};

}