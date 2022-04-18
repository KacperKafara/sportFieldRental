//
// Created by student on 17.04.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Bicycle.h"

using std::string;

BOOST_AUTO_TEST_SUITE(TestSuiteBicycle)

    BOOST_AUTO_TEST_CASE(BicycleGetActualRentalPriceTest) {
        Bicycle bicycle("WLS", 123);
        BOOST_TEST(bicycle.getActualRentalPrice() == 123);
    }

BOOST_AUTO_TEST_SUITE_END()