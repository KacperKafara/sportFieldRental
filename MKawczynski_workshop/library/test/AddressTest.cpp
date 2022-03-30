#include <boost/test/unit_test.hpp>
#include "model/Address.h"

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)
    BOOST_AUTO_TEST_CASE(AddressGetterTest)
    {
        Address testAddress("testCity","testStreet","7357");
        BOOST_TEST(testAddress.getCity().compare("testCity")==0);
        BOOST_TEST(testAddress.getStreet().compare("testStreet")==0);
        BOOST_TEST(testAddress.getNumber().compare("7357")==0);
    }

BOOST_AUTO_TEST_SUITE_END()