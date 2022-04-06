//
// Created by student on 02.04.2022.
//

#include <boost/test/unit_test.hpp>
#include <string>
#include "model/Vehicle.h"

using std::string;

BOOST_AUTO_TEST_SUITE(TestSuiteVehicle)

    BOOST_AUTO_TEST_CASE(VehicleConstructorTest) {
        Vehicle v("ABCD", 123);
        BOOST_TEST(v.getPlateNumber().compare("ABCD") == 0);
        BOOST_TEST(v.getBasePrice() == 123);
    }

    BOOST_AUTO_TEST_CASE(VehicleSetterPlateNumberTest) {
        Vehicle v("ABCD", 123);
        v.setPlateNumber("ABC");
        BOOST_TEST(v.getPlateNumber().compare("ABC") == 0);
        v.setPlateNumber("");
        BOOST_TEST(v.getPlateNumber().compare("") != 0);
    }

    BOOST_AUTO_TEST_CASE(VehicleSetterBasePriceTest) {
        Vehicle v("ABCD", 123);
        v.setBasePrice(1234);
        BOOST_TEST(v.getBasePrice() == 1234);
    }

    BOOST_AUTO_TEST_CASE(VehicleSetterRentedTest) {
        Vehicle v("ABCD", 123);
        BOOST_TEST(v.isRented() == false);
        v.setRented(true);
        BOOST_TEST(v.isRented() == true);
    }

BOOST_AUTO_TEST_SUITE_END()