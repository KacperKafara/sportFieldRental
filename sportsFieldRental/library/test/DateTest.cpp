//
// Created by student on 02.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Date.h"

BOOST_AUTO_TEST_SUITE(DateSuiteTest)

BOOST_AUTO_TEST_CASE(DateEqualityTest) {
    Date date1(2000,1,1,12,30);
    Date date2(2000,1,1,12,30);

    BOOST_REQUIRE_EQUAL(date1==date2,true);
}

BOOST_AUTO_TEST_CASE(DateMinorityTest) {
        Date date1(2000,1,1,12,30);
        Date date2(2000,1,1,12,15);

        BOOST_REQUIRE_EQUAL(date1>date2,true);
}

    BOOST_AUTO_TEST_CASE(DateValidityTest) {
        Date date(-2000,-1,-1,-12,-30);

        BOOST_REQUIRE_EQUAL(date.isValidDate(),false);
    }


BOOST_AUTO_TEST_SUITE_END()