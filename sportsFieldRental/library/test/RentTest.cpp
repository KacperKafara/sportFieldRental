//
// Created by student on 03.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/events/Training.h"
#include "model/events/Tournament.h"
#include "model/clientTypes/School.h"
#include "model/clientTypes/LeagueA.h"
#include "model/clientTypes/Club.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Field.h"
#include "model/Date.h"

BOOST_AUTO_TEST_SUITE(RentSuiteTest)

BOOST_AUTO_TEST_CASE(RentConstructorTest){
    eventPtr event = make_shared<Training>();
    clientTypePtr clientType = make_shared<School>();
    addressPtr address = make_shared<Address>("1", "2", "3");
    clientPtr client = make_shared<Client>(1, "123", "123456789", address, clientType);
    addressPtr address1 = make_shared<Address>("2", "3", "4");
    fieldPtr field = make_shared<Field>(1, 200, 300, address1);
    datePtr date = make_shared<Date>(1,1,1,1,1);
    rentPtr rent = make_shared<Rent>(1, event, client, field,date);
    BOOST_REQUIRE_EQUAL(rent->getId(), 1);
    BOOST_REQUIRE_EQUAL(rent->getEvent(), event->getEventType());
    BOOST_REQUIRE_EQUAL(rent->getClient(), client);
    BOOST_REQUIRE_EQUAL(rent->getField(), field);
}

BOOST_AUTO_TEST_CASE(RentHoursTest){
    eventPtr event = make_shared<Training>();
    clientTypePtr clientType = make_shared<School>();
    addressPtr address = make_shared<Address>("1", "2", "3");
    clientPtr client = make_shared<Client>(1, "123", "123456789", address, clientType);

    addressPtr address1 = make_shared<Address>("2", "3", "4");
    fieldPtr field = make_shared<Field>(1, 200, 300, address1);
    datePtr date1 = make_shared<Date>(1,1,1,12,1);
    datePtr date2 = make_shared<Date>(1,1,1,14,1);
    rentPtr rent = make_shared<Rent>(1, event, client, field,date1);

    rent->endRent(date2);

    BOOST_REQUIRE_EQUAL(rent->getRentHours(), 2);
}

BOOST_AUTO_TEST_CASE(RentInfoTest){

    eventPtr event = make_shared<Tournament>();
    leaguePtr league = make_shared<LeagueA>();
    clientTypePtr clientType = make_shared<Club>(league);
    addressPtr address = make_shared<Address>("1", "2", "3");
    clientPtr client = make_shared<Client>(1, "123", "123456789", address, clientType);

    addressPtr address1 = make_shared<Address>("2", "3", "4");
    fieldPtr field = make_shared<Field>(1, 200, 300, address1);
    datePtr date1 = make_shared<Date>(1,1,1,12,1);
    datePtr date2 = make_shared<Date>(1,1,1,14,1);
    rentPtr rent = make_shared<Rent>(1, event, client, field,date1);

    rent->endRent(date2);

    BOOST_REQUIRE_EQUAL(rent->getRentCost(), 390);
}

BOOST_AUTO_TEST_CASE(RentEndRentTest){
    eventPtr event = make_shared<Training>();
    clientTypePtr clientType = make_shared<School>();
    addressPtr address = make_shared<Address>("1", "2", "3");
    clientPtr client = make_shared<Client>(1, "123", "123456789", address, clientType);

    addressPtr address1 = make_shared<Address>("2", "3", "4");
    fieldPtr field = make_shared<Field>(1, 200, 300, address1);
    datePtr date1 = make_shared<Date>(1,1,1,12,1);
    datePtr date2 = make_shared<Date>(1,1,1,11,1);
    rentPtr rent = make_shared<Rent>(1, event, client, field,date1);

    rent->endRent(date2);

    BOOST_REQUIRE_EQUAL(rent->getRentHours(), 0);
}

BOOST_AUTO_TEST_SUITE_END()