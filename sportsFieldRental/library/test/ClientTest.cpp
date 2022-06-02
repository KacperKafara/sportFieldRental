//
// Created by student on 02.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "Client.h"

BOOST_AUTO_TEST_SUITE(ClientSuiteTest)

BOOST_AUTO_TEST_CASE(ClientIdTest) {
    Client client(1, "szkola", "123456789");
    BOOST_REQUIRE_EQUAL(client.getId(), 1);
}

BOOST_AUTO_TEST_CASE(ClientNameTest) {
    Client client(1, "szkola", "123456789");
    BOOST_REQUIRE_EQUAL(client.getName(), "szkola");
}

BOOST_AUTO_TEST_CASE(ClientPhoneNumberTest) {
    Client client(1, "szkola", "123456789");
    BOOST_REQUIRE_EQUAL(client.getPhoneNumber(), "123456789");
}

BOOST_AUTO_TEST_SUITE_END()