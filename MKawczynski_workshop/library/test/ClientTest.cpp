#include <boost/test/unit_test.hpp>
#include "model/Client.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClient)
    BOOST_AUTO_TEST_CASE(ClientGetterTest)
    {
        Client testClient("testName","testLastname","7357");
        BOOST_TEST(testClient.getFirstName().compare("testName")==0);
        BOOST_TEST(testClient.getLastName().compare("testLastname")==0);
        BOOST_TEST(testClient.getPersonalID().compare("7357")==0);
    }

    BOOST_AUTO_TEST_CASE(ClientSetterTest)
    {
        Client testClient("testName","testLastname","7357");

        testClient.setFirstName("newTestName");
        BOOST_TEST(testClient.getFirstName().compare("newTestName")==0);

        testClient.setFirstName("");
        BOOST_TEST(testClient.getFirstName().compare("")!=0);

        testClient.setLastName("newTestLastname");
        BOOST_TEST(testClient.getLastName().compare("newTestLastname")==0);

        testClient.setLastName("");
        BOOST_TEST(testClient.getLastName().compare("")!=0);
    }

BOOST_AUTO_TEST_SUITE_END()