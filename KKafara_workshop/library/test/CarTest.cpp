//
// Created by student on 17.04.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Car.h"

using std::string;

BOOST_AUTO_TEST_SUITE(TestSuitCar)

    BOOST_AUTO_TEST_CASE(CarGetActualRentalPriceTest) {
//        Car car("WLS", 1000, 1000, SegmentType::A);
        Car *car = new Car("WLS", 1000, 1000, SegmentType::A);
        BOOST_TEST(car->getActualRentalPrice() == 1000);
        delete car;
        Car *car1 = new Car("WLS", 1000, 1000, SegmentType::E);
        BOOST_TEST(car1->getActualRentalPrice() == 1500);
        delete car1;
        Car *car2 = new Car("WLS", 1000, 2000, SegmentType::B);
        BOOST_TEST(car2->getActualRentalPrice() == 1650);
        delete car2;
    }

BOOST_AUTO_TEST_SUITE_END();