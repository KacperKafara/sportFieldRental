#include <boost/test/unit_test.hpp>

#include "model/Client.h"

BOOST_AUTO_TEST_SUITE(ClientSuiteCorrect)

BOOST_AUTO_TEST_CASE(ClientFirstNameCase) {
    Client client("Adam", "Smith", "123");
    BOOST_REQUIRE_EQUAL(client.getFirstName(), "Adam");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ClientSuiteFailure)

BOOST_AUTO_TEST_CASE(ClientFirstNameRequire) {
    Client client("Adam", "Smith", "123");
    BOOST_REQUIRE_EQUAL(client.getFirstName(), "Error"); //REQUIRE_EQUAL = fatal error - end test case
    BOOST_REQUIRE_EQUAL(client.getFirstName(), "Adam"); //not invoked due to previous fatal error
}

BOOST_AUTO_TEST_CASE(ClientFirstNameCheck) {
    Client client("Adam", "Smith", "123");
    BOOST_CHECK_EQUAL(client.getFirstName(), "Error"); //CHECK_EQUAL = error - but continue testing
    BOOST_CHECK_EQUAL(client.getFirstName(), "Adam");
}

BOOST_AUTO_TEST_SUITE_END()
