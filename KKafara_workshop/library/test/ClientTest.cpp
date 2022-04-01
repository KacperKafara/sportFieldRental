#include <boost/test/unit_test.hpp>

#include "model/Client.h"

using std::string;

struct TestSuiteClientFixture {
    const string testFirstName = "Kacper";
    const string testLastName = "Kafara";
    const string testPersonalID = "242412";
    Address *testaddress1;
    Address *testaddress2;

    TestSuiteClientFixture() {
        testaddress1 = new Address("Warsaw", "Batorego", "22");
        testaddress2 = new Address("Warsaw", "Aleje Jerozolimskie", "13");
    }

    ~TestSuiteClientFixture() {
        delete testaddress1;
        delete testaddress2;
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ClientConstructorTest) {
        Client client(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(client.getFirstName().compare(testFirstName) == 0);
        BOOST_TEST(client.getLastName().compare(testLastName) == 0);
        BOOST_TEST(client.getPersonalId().compare(testPersonalID) == 0);
        BOOST_TEST(client.getAddress()->getCity().compare(testaddress1->getCity()) == 0);
        BOOST_TEST(client.getAddress()->getStreet().compare(testaddress1->getStreet()) == 0);
        BOOST_TEST(client.getAddress()->getNumber().compare(testaddress1->getNumber()) == 0);
    }

    BOOST_AUTO_TEST_CASE(ClientSetterNameTest) {
        Client client(testFirstName, testLastName, testPersonalID, testaddress1);
        client.setFirstName("Name");
        BOOST_TEST(client.getFirstName().compare("Name") == 0);
        client.setFirstName("");
        BOOST_TEST(client.getFirstName().compare("") != 0);

    }

    BOOST_AUTO_TEST_CASE(ClientSetterLastNameTest) {
        Client client(testFirstName, testLastName, testPersonalID, testaddress1);
        client.setLastName("LastName");
        BOOST_TEST(client.getLastName().compare("LastName") == 0);
        client.setLastName("");
        BOOST_TEST(client.getLastName().compare("") != 0);
    }

    BOOST_AUTO_TEST_CASE(ClientSetterAddressTest) {
        Client client(testFirstName, testLastName, testPersonalID, testaddress1);
        client.setAddress(testaddress2);
        BOOST_TEST(client.getAddress()->getCity().compare(testaddress2->getCity()) == 0);
        BOOST_TEST(client.getAddress()->getStreet().compare(testaddress2->getStreet()) == 0);
        BOOST_TEST(client.getAddress()->getNumber().compare(testaddress2->getNumber()) == 0);
        client.setAddress(NULL);
        BOOST_TEST(client.getAddress()->getCity().compare(testaddress2->getCity()) == 0);
        BOOST_TEST(client.getAddress()->getStreet().compare(testaddress2->getStreet()) == 0);
        BOOST_TEST(client.getAddress()->getNumber().compare(testaddress2->getNumber()) == 0);
    }

BOOST_AUTO_TEST_SUITE_END()