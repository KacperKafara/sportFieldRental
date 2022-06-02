//
// Created by student on 02.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Address.h"

using std::make_shared;

BOOST_AUTO_TEST_SUITE(ClientSuiteTest)

BOOST_AUTO_TEST_CASE(ClientIdTest) {
    addressPtr address = make_shared<Address>("123", "456", "789");
    Client client(1, "szkola", "123456789", address);
    BOOST_REQUIRE_EQUAL(client.getId(), 1);
}

BOOST_AUTO_TEST_CASE(ClientNameTest) {
    addressPtr address = make_shared<Address>("123", "456", "789");
    Client client(1, "szkola", "123456789", address);
    BOOST_REQUIRE_EQUAL(client.getName(), "szkola");
}

BOOST_AUTO_TEST_CASE(ClientPhoneNumberTest) {
    addressPtr address = make_shared<Address>("123", "456", "789");
    Client client(1, "szkola", "123456789", address);
    BOOST_REQUIRE_EQUAL(client.getPhoneNumber(), "123456789");
}

BOOST_AUTO_TEST_CASE(ClientAddressTest) {
    addressPtr address = make_shared<Address>("123", "456", "789");
    Client client(1, "szkola", "123456789", address);
    BOOST_REQUIRE_EQUAL(client.getAddress(), address);
}

BOOST_AUTO_TEST_SUITE_END()