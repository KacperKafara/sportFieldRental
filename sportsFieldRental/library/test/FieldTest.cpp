//
// Created by student on 02.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Field.h"
#include "model/Address.h"


BOOST_AUTO_TEST_SUITE(FieldSuiteTest)

BOOST_AUTO_TEST_CASE(FieldIdTest) {
    addressPtr address = make_shared<Address>("123", "456", "789");
    Field field(1, 123, 456, address);
    BOOST_REQUIRE_EQUAL(field.getId(), 1);
}

BOOST_AUTO_TEST_CASE(FieldTribuneCapacityTest) {
    addressPtr address = make_shared<Address>("123", "456", "789");
    Field field(1, 123, 456, address);
    BOOST_REQUIRE_EQUAL(field.getTribuneCapacity(), 123);
}

BOOST_AUTO_TEST_CASE(FieldBaseCostTest) {
    addressPtr address = make_shared<Address>("123", "456", "789");
    Field field(1, 123, 456, address);
    BOOST_REQUIRE_EQUAL(field.getBaseCost(), 456);
}

BOOST_AUTO_TEST_CASE(ClientAddressTest) {
    addressPtr address = make_shared<Address>("123", "456", "789");
    Field field(1, 123, 456, address);
    BOOST_REQUIRE_EQUAL(field.getAddress(), address);
}

BOOST_AUTO_TEST_SUITE_END()