//
// Created by student on 02.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Address.h"

BOOST_AUTO_TEST_SUITE(AddressSuiteTest)

BOOST_AUTO_TEST_CASE(AddressCityTest) {
    Address address("123", "456", "789");
    BOOST_REQUIRE_EQUAL(address.getCity(), "123");
}

BOOST_AUTO_TEST_CASE(AddressStreetTest) {
    Address address("123", "456", "789");
    BOOST_REQUIRE_EQUAL(address.getStreet(), "456");
}

BOOST_AUTO_TEST_CASE(AddressNumberTest) {
    Address address("123", "456", "789");
    BOOST_REQUIRE_EQUAL(address.getNumber(), "789");
}

BOOST_AUTO_TEST_SUITE_END()