//
// Created by student on 01.04.2022.
//

#include <boost/test/unit_test.hpp>
#include <string>
#include "model/Address.h"

using std::string;

struct TestSuiteAddressFixture {
    const string testCity = "Warsaw";
    const string testStreet = "Bemowo";
    const string testNumber = "24";
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress, TestSuiteAddressFixture)

    BOOST_AUTO_TEST_CASE(AddressConstructorTest) {
        Address adr(testCity, testStreet, testNumber);
        BOOST_TEST(adr.getCity().compare(testCity) == 0);
        BOOST_TEST(adr.getStreet().compare(testStreet) == 0);
        BOOST_TEST(adr.getNumber().compare(testNumber) == 0);
    }


BOOST_AUTO_TEST_SUITE_END();