//
// Created by student on 05.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/repositories/RentRepository.h"
#include "model/Rent.h"
#include "model/events/Training.h"
#include "model/clientTypes/School.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Field.h"
#include "model/Date.h"

BOOST_AUTO_TEST_SUITE(RentRepositorySuiteTest)

BOOST_AUTO_TEST_CASE(RentRepositoryAddTest) {
    RentRepository repo;
    eventPtr event = make_shared<Training>();
    clientTypePtr clientType = make_shared<School>();
    addressPtr address = make_shared<Address>("1", "2", "3");
    clientPtr client = make_shared<Client>(1, "123", "1234", address, clientType);
    addressPtr address1 = make_shared<Address>("2", "3", "4");
    fieldPtr field = make_shared<Field>(1, 200, 300, address1);
    datePtr date = make_shared<Date>(1,1,1,1,1);
    rentPtr rent = make_shared<Rent>(1, event, client, field,date);
    BOOST_REQUIRE_EQUAL(repo.getRents().size(), 0);
    BOOST_REQUIRE_EQUAL(repo.getArchiveRents().size(), 0);
    repo.add(rent);
    BOOST_REQUIRE_EQUAL(repo.getRents().size(), 1);
    BOOST_REQUIRE_EQUAL(repo.getArchiveRents().size(), 0);
}

BOOST_AUTO_TEST_CASE(RentRepositoryMakeArchiveTest) {
    RentRepository repo;
    eventPtr event = make_shared<Training>();
    clientTypePtr clientType = make_shared<School>();
    addressPtr address = make_shared<Address>("1", "2", "3");
    clientPtr client = make_shared<Client>(1, "123", "1234", address, clientType);
    addressPtr address1 = make_shared<Address>("2", "3", "4");
    fieldPtr field = make_shared<Field>(1, 200, 300, address1);
    datePtr date = make_shared<Date>(2020,1,1,14,1);
    rentPtr rent = make_shared<Rent>(1, event, client, field,date);
    BOOST_REQUIRE_EQUAL(repo.getRents().size(), 0);
    BOOST_REQUIRE_EQUAL(repo.getArchiveRents().size(), 0);
    repo.add(rent);
    repo.makeArchive(1,date);
    BOOST_REQUIRE_EQUAL(repo.getRents().size(), 0);
    BOOST_REQUIRE_EQUAL(repo.getArchiveRents().size(), 1);
}

BOOST_AUTO_TEST_CASE(RentRepositoryGetTest) {
    RentRepository repo;
    eventPtr event = make_shared<Training>();
    clientTypePtr clientType = make_shared<School>();
    addressPtr address = make_shared<Address>("1", "2", "3");
    clientPtr client = make_shared<Client>(1, "123", "1234", address, clientType);
    addressPtr address1 = make_shared<Address>("2", "3", "4");
    clientPtr client1 = make_shared<Client>(2, "234", "5678", address1, clientType);
    fieldPtr field = make_shared<Field>(2, 200, 300, address1);
    datePtr date = make_shared<Date>(1,1,1,1,1);
    rentPtr rent = make_shared<Rent>(1, event, client, field,date);
    rentPtr rent1 = make_shared<Rent>(2, event, client1, field, date);
    BOOST_REQUIRE_EQUAL(repo.getRents().size(), 0);
    BOOST_REQUIRE_EQUAL(repo.getArchiveRents().size(), 0);
    repo.add(rent);
    repo.add(rent1);
    BOOST_REQUIRE_EQUAL(repo.get(2)[0], rent);
    BOOST_REQUIRE_EQUAL(repo.get("1", "2", "3")[0], rent);
}

BOOST_AUTO_TEST_SUITE_END()