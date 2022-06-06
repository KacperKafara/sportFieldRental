//
// Created by student on 05.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/repositories/RentRepository.h"
#include "model/events/Tournament.h"
#include "model/clientTypes/LeagueA.h"
#include "model/clientTypes/Club.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Rent.h"
#include "model/Field.h"
#include "model/Date.h"
#include "model/managers/RentManager.h"
#include "model/managers/ClientManager.h"

BOOST_AUTO_TEST_SUITE(RentManagerSuiteTest)

BOOST_AUTO_TEST_CASE(RentManagerBegindAndEnd) {
    eventPtr event = make_shared<Tournament>();
    leaguePtr league = make_shared<LeagueA>();
    clientTypePtr clientType = make_shared<Club>(league);
    addressPtr address1 = make_shared<Address>("1", "2", "3");
    addressPtr address2 = make_shared<Address>("A", "B", "C");
    clientPtr client = make_shared<Client>(1, "123", "1234", address1, clientType);
    fieldPtr field = make_shared<Field>(1, 200, 300, address2);
    datePtr dateStart = make_shared<Date>(2020,1,1,12,1);
    datePtr dateEnd = make_shared<Date>(2020,1,1,12,1);
    RentManager rentManager;

    rentManager.begin(1, event, field, client, dateStart);
    BOOST_REQUIRE_EQUAL(rentManager.getRentRepository()->getRents().size(), 1);

    BOOST_REQUIRE_EQUAL(rentManager.getRentRepository()->getArchiveRents().size(), 0);
    rentManager.end(1,dateEnd);
    BOOST_REQUIRE_EQUAL(rentManager.getRentRepository()->getRents().size(), 0);
    BOOST_REQUIRE_EQUAL(rentManager.getRentRepository()->getArchiveRents().size(), 1);
}

BOOST_AUTO_TEST_CASE(RentManagerGet) {
    eventPtr event = make_shared<Tournament>();
    leaguePtr league = make_shared<LeagueA>();
    clientTypePtr clientType = make_shared<Club>(league);
    addressPtr address1 = make_shared<Address>("1", "2", "3");
    addressPtr address2 = make_shared<Address>("A", "B", "C");
    clientPtr client = make_shared<Client>(1, "123", "1234", address1, clientType);
    fieldPtr field = make_shared<Field>(1, 200, 300, address2);
    datePtr dateStart = make_shared<Date>(2020,1,1,12,1);
    datePtr dateEnd = make_shared<Date>(2020,1,1,12,1);
    RentManager rentManager;

    rentManager.begin(1, event, field, client, dateStart);
    fieldPtr field1 = make_shared<Field>(2, 300, 100, address2);
    rentManager.begin(2, event, field1, client, dateStart);
    BOOST_REQUIRE_EQUAL(rentManager.getAllRentsForClient("1", "2", "3")[0]->getClient(), client);
    BOOST_REQUIRE_EQUAL(rentManager.getAllRentsForField(2)[0]->getField(), field1);
    BOOST_TEST_REQUIRE(rentManager.getAllRentsForField(1)[0]->getField() != field1);
}

BOOST_AUTO_TEST_SUITE_END()