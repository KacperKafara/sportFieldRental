#include <boost/test/unit_test.hpp>

#include "model/Client.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

//    BOOST_AUTO_TEST_CASE(AssertionsTests) {
//        BOOST_TEST(1.0/3.0 == 0.333, boost::test_tools::tolerance(0.01));
//    }

    BOOST_AUTO_TEST_CASE(ClientConstructorTest) {
        Client client("Kacper", "Kafara", "242412");

        BOOST_TEST(client.getFirstName().compare("Kacper") == 0);
        BOOST_TEST(client.getLastName().compare("Kafara") == 0);
        BOOST_TEST(client.getPersonalId().compare("242412") == 0);
    }

    BOOST_AUTO_TEST_CASE(ClientSetterNameTest) {
        Client client("Kacper", "Kafara", "242412");
        client.setFirstName("Name");
        BOOST_TEST(client.getFirstName().compare("Name") == 0);
        client.setFirstName("");
        BOOST_TEST(client.getFirstName().compare("") != 0);

    }

    BOOST_AUTO_TEST_CASE(ClientSetterLastNameTest) {
        Client client("Kacper", "Kafara", "242412");
        client.setLastName("LastName");
        BOOST_TEST(client.getLastName().compare("LastName") == 0);
        client.setLastName("");
        BOOST_TEST(client.getLastName().compare("") != 0);
    }

BOOST_AUTO_TEST_SUITE_END()