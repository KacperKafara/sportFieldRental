#include <boost/test/unit_test.hpp>
#include "model/Client.h"

struct TestSuiteClientFixture
{
    const std::string testFirstName="testFirstName";
    const std::string testLastName="testLastName";
    const std::string testPersonalID="0123456789";
    Address *testAddress1;
    Address *testAddress2;

    TestSuiteClientFixture()
    {
        testAddress1=new Address("testCity1", "testStreet1", "1");
        testAddress2=new Address("testCity2", "testStreet2", "2");
    }

    ~TestSuiteClientFixture()
    {
        delete testAddress1;
        delete testAddress2;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)
    BOOST_AUTO_TEST_CASE(ClientGetterTest)
    {
        Client testClient(testFirstName,testLastName,testPersonalID,testAddress1);
        BOOST_TEST(testClient.getFirstName().compare(testFirstName)==0);
        BOOST_TEST(testClient.getLastName().compare(testLastName)==0);
        BOOST_TEST(testClient.getPersonalID().compare(testPersonalID)==0);
        BOOST_TEST(testClient.getAddress()->getCity().compare(testAddress1->getCity())==0);
        BOOST_TEST(testClient.getAddress()->getStreet().compare(testAddress1->getStreet())==0);
        BOOST_TEST(testClient.getAddress()->getNumber().compare(testAddress1->getNumber())==0);
    }

    BOOST_AUTO_TEST_CASE(ClientSetterTest)
    {
        Client testClient(testFirstName,testLastName,testPersonalID,testAddress1);

        testClient.setFirstName("newTestName");
        BOOST_TEST(testClient.getFirstName().compare("newTestName")==0);

        testClient.setFirstName("");
        BOOST_TEST(testClient.getFirstName().compare("")!=0);

        testClient.setLastName("newTestLastname");
        BOOST_TEST(testClient.getLastName().compare("newTestLastname")==0);

        testClient.setLastName("");
        BOOST_TEST(testClient.getLastName().compare("")!=0);

        testClient.setAddress(testAddress2);
        BOOST_TEST(testClient.getAddress()->getCity().compare(testAddress2->getCity())==0);
        BOOST_TEST(testClient.getAddress()->getStreet().compare(testAddress2->getStreet())==0);
        BOOST_TEST(testClient.getAddress()->getNumber().compare(testAddress2->getNumber())==0);
        testClient.setAddress(NULL);
        BOOST_TEST(testClient.getAddress()->getCity().compare(testAddress2->getCity())==0);
        BOOST_TEST(testClient.getAddress()->getStreet().compare(testAddress2->getStreet())==0);
        BOOST_TEST(testClient.getAddress()->getNumber().compare(testAddress2->getNumber())==0);
    }

BOOST_AUTO_TEST_SUITE_END()