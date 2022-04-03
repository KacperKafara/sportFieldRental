//
// Created by student on 03.04.2022.
//

#include <boost/test/unit_test.hpp>

#include "model/Rent.h"

using std::string;

BOOST_AUTO_TEST_SUITE(TestSuiteRent)

    BOOST_AUTO_TEST_CASE(RentConstructorTest) {
        Address address("Warsaw", "Batorego", "24");
        Client client("Kacper", "Kafara", "242412", &address);
        Vehicle vehicle("WLS 12345", 1234);
        Rent rent(1, &client, &vehicle);
        BOOST_TEST(rent.getId() == 1);
        BOOST_TEST(rent.getClient()->getFirstName().compare("Kacper") == 0);
        BOOST_TEST(rent.getClient()->getLastName().compare("Kafara") == 0);
        BOOST_TEST(rent.getClient()->getPersonalId().compare("242412") == 0);
        BOOST_TEST(rent.getClient()->getAddress()->getCity().compare("Warsaw") == 0);
        BOOST_TEST(rent.getClient()->getAddress()->getStreet().compare("Batorego") == 0);
        BOOST_TEST(rent.getClient()->getAddress()->getNumber().compare("24") == 0);
        BOOST_TEST(rent.getVehicle()->getPlateNumber().compare("WLS 12345") == 0);
        BOOST_TEST(rent.getVehicle()->getBasePrice() == 1234);
        BOOST_TEST(rent.getClient()->getCurrentRents()[0]->getId() == 1);
    }

BOOST_AUTO_TEST_SUITE_END()