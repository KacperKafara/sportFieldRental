//
// Created by student on 02.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Date.h"
#include "typedefs.h"

BOOST_AUTO_TEST_SUITE(DateSuiteTest)

BOOST_AUTO_TEST_CASE(DateMinorityTest) {
        //Date date1(1,1,1,11,1);
        //Date date2(1,1,1,12,1);

        datePtr date1 = make_shared<Date>(1,1,1,14,1);
        datePtr date2 = make_shared<Date>(1,1,1,12,1);

        BOOST_REQUIRE_EQUAL(date1>date2,true);
}

BOOST_AUTO_TEST_CASE(DateValidityTest) {
    Date date(-2000,-1,-1,-12,-30);

    BOOST_REQUIRE_EQUAL(date.isValidDate(),true);
}

BOOST_AUTO_TEST_CASE(DateGetInfoTest) {
    Date date(2022,5,6,12,25);

    BOOST_REQUIRE_EQUAL(date.getInfo(),"6.5.2022 12:25");
}

BOOST_AUTO_TEST_CASE(DateSetTodayDateTest) {
    Date date(2022,5,6,12,25);

    date.setTodayDate();

    BOOST_REQUIRE_EQUAL(date.getInfo()=="6.5.2022 12:25",false);
}

BOOST_AUTO_TEST_CASE(DateConstuctorTest) {
    Date date1(-1,-2,-3,-4,-5);

    Date date2(1,2,3,4,5);

    date2.setTodayDate();

    BOOST_REQUIRE_EQUAL(date1.getInfo(),date2.getInfo());
}

BOOST_AUTO_TEST_CASE(DateAssignTest) {
    Date date1(1,2,3,4,5);

    Date date2(11,22,33,44,55);

    date2=date1;

    BOOST_REQUIRE_EQUAL(date1.getInfo(),date2.getInfo());
}

BOOST_AUTO_TEST_SUITE_END()