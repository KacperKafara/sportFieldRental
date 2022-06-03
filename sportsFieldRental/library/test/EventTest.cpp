//
// Created by student on 03.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/events/Training.h"
#include "typedefs.h"

BOOST_AUTO_TEST_SUITE(EventSuiteTest)

BOOST_AUTO_TEST_CASE(EventTypeTest) {
    eventPtr event = make_shared<Training>();
    BOOST_REQUIRE_EQUAL(event->getEventType(), "Training");
}

BOOST_AUTO_TEST_CASE(EventDiscountTest) {
    eventPtr event = make_shared<Training>();
    BOOST_REQUIRE_EQUAL(event->getDiscount(), 0.15);
}

BOOST_AUTO_TEST_SUITE_END()