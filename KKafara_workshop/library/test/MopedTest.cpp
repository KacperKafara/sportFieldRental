//
// Created by student on 17.04.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Moped.h"

using std::string;

BOOST_AUTO_TEST_SUITE(TestSuitMoped)

    BOOST_AUTO_TEST_CASE(MopedGetActualRentalPriceTest) {
        Moped moped("WLS", 1000, 1000);
        BOOST_TEST(moped.getActualRentalPrice() == 1000);
        Moped moped1("WLS", 1000, 1500);
        BOOST_TEST(moped1.getActualRentalPrice() == 1250);
        Moped moped2("WLS", 1000, 2000);
        BOOST_TEST(moped2.getActualRentalPrice() == 1500);
    }

BOOST_AUTO_TEST_SUITE_END()