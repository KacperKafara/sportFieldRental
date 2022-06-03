//
// Created by student on 02.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Address.h"
#include "model/clientTypes/School.h"
#include "model/clientTypes/Club.h"
#include "model/clientTypes/LeagueA.h"

BOOST_AUTO_TEST_SUITE(ClientSuiteTest)

BOOST_AUTO_TEST_CASE(ClientIdTest) {
    addressPtr address = make_shared<Address>("123", "456", "789");
    clientTypePtr type = make_shared<School>();
    Client client(1, "szkola", "123456789", address, type);
    BOOST_REQUIRE_EQUAL(client.getId(), 1);
}

BOOST_AUTO_TEST_CASE(ClientNameTest) {
    addressPtr address = make_shared<Address>("123", "456", "789");
    clientTypePtr type = make_shared<School>();
    Client client(1, "szkola", "123456789", address, type);
    BOOST_REQUIRE_EQUAL(client.getName(), "szkola");
}

BOOST_AUTO_TEST_CASE(ClientPhoneNumberTest) {
    addressPtr address = make_shared<Address>("123", "456", "789");
    clientTypePtr type = make_shared<School>();
    Client client(1, "szkola", "123456789", address, type);
    BOOST_REQUIRE_EQUAL(client.getPhoneNumber(), "123456789");
}

BOOST_AUTO_TEST_CASE(ClientAddressTest) {
    addressPtr address = make_shared<Address>("123", "456", "789");
    clientTypePtr type = make_shared<School>();
    Client client(1, "szkola", "123456789", address, type);
    BOOST_REQUIRE_EQUAL(client.getAddress(), address);
}

BOOST_AUTO_TEST_CASE(ClientTypeTest) {
    addressPtr address = make_shared<Address>("123", "456", "789");
    leaguePtr league = make_shared<LeagueA>();
    clientTypePtr type1 = make_shared<Club>(league);
    Client client(1, "szkola", "123456789", address, type1);
    BOOST_REQUIRE_EQUAL(client.getClientType()->getType(), "Club");
    BOOST_REQUIRE_EQUAL(client.getClientType()->getInfo(), "Type: Club, League: League A");
}

BOOST_AUTO_TEST_SUITE_END()