#include <gtest/gtest.h>
#include "PiSubmarine/I2C/Api/IDriver.h"
#include "PiSubmarine/I2C/Api/DriverConcept.h"
#include "PiSubmarine/I2C/Api/DriverAsyncConcept.h"
#include "PiSubmarine/I2C/Api/IDriverAsync.h"

namespace PiSubmarine::I2C::Api
{
    TEST(IDriverTest, Test1)
    {
        static_assert(DriverConcept<IDriver>, "IDriver must satisfy DriverConcept");
        static_assert(DriverAsyncConcept<IDriverAsync>, "IDriverAsync must satisfy DriverAsyncConcept");


    }
}
