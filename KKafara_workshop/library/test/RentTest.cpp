//
// Created by student on 03.04.2022.
//

#include <boost/test/unit_test.hpp>

#include "model/Rent.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Bicycle.h"

using std::string;
using std::make_shared;

BOOST_AUTO_TEST_SUITE(TestSuiteRent)

    BOOST_AUTO_TEST_CASE(RentConstructorTest) {
        addressPtr address = make_shared<Address>("Warsaw", "Batorego", "24");
        clientPtr client = make_shared<Client>("Kacper", "Kafara", "242412", address);
        bicyclePtr vehicle = make_shared<Bicycle>("WLS 12345", 1234);
        rentPtr rent = make_shared<Rent>(1, client, vehicle, boost::date_time::not_a_date_time);
        ptime now = second_clock::local_time();
        BOOST_TEST_REQUIRE(!rent->getBeginTime().is_not_a_date_time());
        BOOST_TEST(rent->getBeginTime() == now);
        BOOST_TEST(rent->getId() == 1);
        BOOST_TEST(rent->getClient()->getFirstName().compare("Kacper") == 0);
        BOOST_TEST(rent->getClient()->getLastName().compare("Kafara") == 0);
        BOOST_TEST(rent->getClient()->getPersonalId().compare("242412") == 0);
        BOOST_TEST(rent->getClient()->getAddress()->getCity().compare("Warsaw") == 0);
        BOOST_TEST(rent->getClient()->getAddress()->getStreet().compare("Batorego") == 0);
        BOOST_TEST(rent->getClient()->getAddress()->getNumber().compare("24") == 0);
        BOOST_TEST(rent->getVehicle()->getPlateNumber().compare("WLS 12345") == 0);
        BOOST_TEST(rent->getVehicle()->getBasePrice() == 1234);
//        BOOST_TEST(rent.getClient()->getCurrentRents()[0]->getId() == 1);
    }

    BOOST_AUTO_TEST_CASE(RentEndTimeTest) {
        addressPtr address = make_shared<Address>("Warsaw", "Batorego", "24");
        clientPtr client = make_shared<Client>("Kacper", "Kafara", "242412", address);
        bicyclePtr vehicle = make_shared<Bicycle>("WLS 12345", 1234);
        rentPtr rent = make_shared<Rent>(1, client, vehicle, boost::date_time::not_a_date_time);
        ptime t1 = ptime(boost::gregorian::date(2015,5,13),hours(9)+minutes(25));
        ptime t2 = ptime(boost::gregorian::date(2023,5,13),hours(9)+minutes(25));
        ptime now = second_clock::local_time();
        BOOST_TEST_REQUIRE(rent->getEndTime().is_not_a_date_time());
        rent->endRent(t1);
        BOOST_TEST(rent->getEndTime() == now);
        rent->endRent(t2);
        BOOST_TEST(rent->getEndTime() != t2);
        rent->endRent(t1);
        BOOST_TEST(rent->getEndTime() != t1);
    }

    BOOST_AUTO_TEST_CASE(RentGetDaysTest) {
        addressPtr address = make_shared<Address>("Warsaw", "Batorego", "24");
        clientPtr client = make_shared<Client>("Kacper", "Kafara", "242412", address);
        bicyclePtr vehicle = make_shared<Bicycle>("WLS 12345", 1234);
        rentPtr rent = make_shared<Rent>(1, client, vehicle, boost::date_time::not_a_date_time);
        ptime t2 = rent->getBeginTime() + minutes(1);
        rent->endRent(t2);
        BOOST_TEST(rent->getRentDays() == 0);
        rentPtr rent1 = make_shared<Rent>(1, client, vehicle, not_a_date_time);
        t2 = rent1->getBeginTime() + hours(1);
        rent1->endRent(t2);
        BOOST_TEST(rent1->getRentDays() == 1);
        rentPtr rent2 = make_shared<Rent>(1, client, vehicle, not_a_date_time);
        t2 = rent2->getBeginTime() + hours(23) + minutes(59);
        rent2->endRent(t2);
        BOOST_TEST(rent2->getRentDays() == 1);
        rentPtr rent3 = make_shared<Rent>(1, client, vehicle, not_a_date_time);
        t2 = rent3->getBeginTime() + hours(24);
        rent3->endRent(t2);
        BOOST_TEST(rent3->getRentDays() == 2);
    }

    BOOST_AUTO_TEST_CASE(RentEndRentTest) {
        addressPtr address = make_shared<Address>("Warsaw", "Batorego", "24");
        clientPtr client = make_shared<Client>("Kacper", "Kafara", "242412", address);
        bicyclePtr vehicle = make_shared<Bicycle>("WLS 12345", 1234);
        rentPtr rent = make_shared<Rent>(1, client, vehicle, boost::date_time::not_a_date_time);
        rentPtr rent1 = make_shared<Rent>(2, client, vehicle, not_a_date_time);
        ptime t2 = rent->getBeginTime() + hours(48);
//        BOOST_TEST(client.getCurrentRents().size() == 2);
        rent->endRent(t2);
//        BOOST_TEST(client.getCurrentRents().size() == 1);
    }

    BOOST_AUTO_TEST_CASE(RentGetRentCostTest) {
        addressPtr address = make_shared<Address>("Warsaw", "Batorego", "24");
        clientPtr client = make_shared<Client>("Kacper", "Kafara", "242412", address);
        bicyclePtr vehicle = make_shared<Bicycle>("WLS 12345", 1234);
        rentPtr rent = make_shared<Rent>(1, client, vehicle, boost::date_time::not_a_date_time);
        ptime t1 = rent->getBeginTime() + minutes(1);
        rent->endRent(t1);
        BOOST_TEST(rent->getRentCost() == 0);
        rentPtr rent1 = make_shared<Rent>(2, client, vehicle, not_a_date_time);
        ptime t2 = rent->getBeginTime() + hours(48);
        rent1->endRent(t2);
        BOOST_TEST(rent1->getRentCost() == 3702);
    }

    BOOST_AUTO_TEST_CASE(RentChangeCostTest) {
        addressPtr address = make_shared<Address>("Warsaw", "Batorego", "24");
        clientPtr client = make_shared<Client>("Kacper", "Kafara", "242412", address);
        bicyclePtr vehicle = make_shared<Bicycle>("WLS 12345", 1234);
        rentPtr rent = make_shared<Rent>(1, client, vehicle, boost::date_time::not_a_date_time);
        ptime t1 = rent->getBeginTime() + hours(48);
        rent->endRent(t1);
        BOOST_TEST(rent->getRentCost() == 3702);
        vehicle->setBasePrice(10);
        BOOST_TEST(rent->getRentCost() == 3702);
    }

BOOST_AUTO_TEST_SUITE_END()