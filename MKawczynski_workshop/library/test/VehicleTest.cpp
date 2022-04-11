#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"

struct TestSuiteVehicleFixture
{
    const std::string testPlateNumber1="012345";
    const unsigned int testBasePrice1=1;

    const std::string testPlateNumber2="543210";
    const unsigned int testBasePrice2=2;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle, TestSuiteVehicleFixture)
    BOOST_AUTO_TEST_CASE(VehicleGetterTest)
    {
        Vehicle testVehicle(testPlateNumber1,testBasePrice1);
        BOOST_TEST(testVehicle.getPlateNumber().compare(testPlateNumber1)==0);
        BOOST_TEST(testVehicle.getBasePrice()==testBasePrice1);
    }

    BOOST_AUTO_TEST_CASE(VehicleSetterTest)
    {
        Vehicle testVehicle(testPlateNumber1,testBasePrice1);

        testVehicle.setPlateNumber(testPlateNumber2);
        testVehicle.setBasePrice(testBasePrice2);

        BOOST_TEST(testVehicle.getPlateNumber().compare(testPlateNumber2)==0);
        BOOST_TEST(testVehicle.getBasePrice()==testBasePrice2);

        testVehicle.setPlateNumber("");
        BOOST_TEST(testVehicle.getPlateNumber().compare("")!=0);
    }

BOOST_AUTO_TEST_SUITE_END()