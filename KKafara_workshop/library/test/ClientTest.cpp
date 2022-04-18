#include <boost/test/unit_test.hpp>

#include "model/Client.h"
#include "model/Address.h"

using std::string;
using std::make_shared;

struct TestSuiteClientFixture {
    const string testFirstName = "Kacper";
    const string testLastName = "Kafara";
    const string testPersonalID = "242412";
    addressPtr testaddress1;
    addressPtr testaddress2;

    TestSuiteClientFixture() {
        testaddress1 = make_shared<Address>("Warsaw", "Batorego", "22");
        testaddress2 = make_shared<Address>("Warsaw", "Aleje Jerozolimskie", "13");
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ClientConstructorTest) {
        clientPtr client = make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(client->getFirstName().compare(testFirstName) == 0);
        BOOST_TEST(client->getLastName().compare(testLastName) == 0);
        BOOST_TEST(client->getPersonalId().compare(testPersonalID) == 0);
        BOOST_TEST(client->getAddress()->getCity().compare(testaddress1->getCity()) == 0);
        BOOST_TEST(client->getAddress()->getStreet().compare(testaddress1->getStreet()) == 0);
        BOOST_TEST(client->getAddress()->getNumber().compare(testaddress1->getNumber()) == 0);
    }

    BOOST_AUTO_TEST_CASE(ClientSetterNameTest) {
        clientPtr client = make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1);
        client->setFirstName("Name");
        BOOST_TEST(client->getFirstName().compare("Name") == 0);
        client->setFirstName("");
        BOOST_TEST(client->getFirstName().compare("") != 0);

    }

    BOOST_AUTO_TEST_CASE(ClientSetterLastNameTest) {
        clientPtr client = make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1);
        client->setLastName("LastName");
        BOOST_TEST(client->getLastName().compare("LastName") == 0);
        client->setLastName("");
        BOOST_TEST(client->getLastName().compare("") != 0);
    }

    BOOST_AUTO_TEST_CASE(ClientSetterAddressTest) {
        clientPtr client = make_shared<Client>(testFirstName, testLastName, testPersonalID, testaddress1);
        client->setAddress(testaddress2);
        BOOST_TEST(client->getAddress()->getCity().compare(testaddress2->getCity()) == 0);
        BOOST_TEST(client->getAddress()->getStreet().compare(testaddress2->getStreet()) == 0);
        BOOST_TEST(client->getAddress()->getNumber().compare(testaddress2->getNumber()) == 0);
    }

BOOST_AUTO_TEST_SUITE_END()