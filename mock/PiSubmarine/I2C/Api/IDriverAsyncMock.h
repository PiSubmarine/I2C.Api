#pragma once

#include <cstdint>
#include <functional>
#include <thread>
#include <chrono>
#include <stop_token>
#include <vector>
#include <condition_variable>
#include "PiSubmarine/I2C/Api/IDriverAsync.h"
#include "PiSubmarine/I2C/Api/Callback.h"
#include <array>

#include "PiSubmarine/I2C/Api/IDriver.h"

namespace PiSubmarine::I2C::Api
{

	struct I2CRequest
	{
		uint8_t DeviceAddress;
		uint8_t* RxData;
		size_t RxLen;
		std::vector<uint8_t> TxData;
		I2C::Api::Callback Callback;
		bool IsWrite = false;
		std::string Tag;
	};

	class IDriverAsyncMock : public IDriverAsync, public IDriver
	{
	public:
		explicit IDriverAsyncMock(std::array<uint8_t, 0x49>& data) : m_Data(data)
		{
			m_WorkerThread = std::jthread([this](const std::stop_token& st) {
				this->WorkerMethod(st);
				});
		}

		[[nodiscard]] bool GetSimulateError() const
		{
			return m_SimulateError;
		}

		void SetSimulateError(bool value)
		{
			m_SimulateError = value;
		}

		bool Read(uint8_t deviceAddress, uint8_t* rxData, size_t len) override
		{
			memcpy(rxData, m_Data.data() + m_DataOffset, len);
			return !m_SimulateError;
		}

		bool Write(uint8_t deviceAddress, uint8_t* txData, size_t len) override
		{
			m_DataOffset = txData[0];
			memcpy(m_Data.data() + m_DataOffset, txData + 1, len - 1);
			return !m_SimulateError;
		}

		bool ReadAsync(uint8_t deviceAddress, uint8_t* rxData, size_t len, Callback callback) override
		{
			std::lock_guard lock(m_Mutex);
			if (m_HasRequest)
			{
				return false;
			}

			m_Request.DeviceAddress = deviceAddress;
			m_Request.RxData = rxData;
			m_Request.RxLen = len;
			m_Request.Callback = callback;
			m_Request.IsWrite = false;
			m_Request.Tag = "ReadAsync";

			m_HasRequest = true;
			return true;
		}

		bool WriteAsync(uint8_t deviceAddress, uint8_t* txData, size_t len, Callback callback) override
		{
			std::lock_guard lock(m_Mutex);
			if (m_HasRequest)
			{
				return false;
			}

			m_Request.DeviceAddress = deviceAddress;
			m_Request.TxData.resize(len);
			memcpy(m_Request.TxData.data(), txData, len);
			m_Request.Callback = callback;
			m_Request.IsWrite = true;
			m_Request.Tag = "WriteAsync";

			m_HasRequest = true;
			return true;
		}

	private:
		std::array<uint8_t, 0x49>& m_Data;
		std::chrono::milliseconds m_TransactionDelay = std::chrono::milliseconds(250);
		I2CRequest m_Request{ 0 };
		bool m_SimulateError = false;
		bool m_HasRequest = false;
		uint8_t m_DataOffset = 0;
		std::mutex m_Mutex;
		std::jthread m_WorkerThread;

		void WorkerMethod(const std::stop_token& st)
		{
			while (!st.stop_requested())
			{
				std::this_thread::sleep_for(m_TransactionDelay);

				{
					std::lock_guard lock(m_Mutex);
					if (!m_HasRequest)
					{
						continue;
					}
				}

				bool ok = false;
				if (m_Request.IsWrite)
				{
					ok = Write(m_Request.DeviceAddress, m_Request.TxData.data(), m_Request.TxData.size());
				}
				else
				{
					ok = Read(m_Request.DeviceAddress, m_Request.RxData, m_Request.RxLen);
				}

				{
					std::lock_guard lock(m_Mutex);
					m_HasRequest = false;
				}

				m_Request.Callback(m_Request.DeviceAddress, ok);
			}
		}
	};

}
