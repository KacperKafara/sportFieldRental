//
// Created by student on 05.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/repositories/ClientRepository.h"
#include "model/events/Tournament.h"
#include "model/clientTypes/LeagueA.h"
#include "model/clientTypes/Club.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/managers/ClientManager.h"

BOOST_AUTO_TEST_SUITE(ClientRepositorySuiteTest)

BOOST_AUTO_TEST_CASE(ClientManagerAddAndRemoveTest) {
    eventPtr event = make_shared<Tournament>();
    leaguePtr league = make_shared<LeagueA>();
    clientTypePtr clientType = make_shared<Club>(league);
    addressPtr address = make_shared<Address>("1", "2", "3");
    clientPtr client = make_shared<Client>(1, "123", "1234", address, clientType);
    clientRepositoryPtr repo = make_shared<ClientRepository>();
    ClientManager clientManager(repo);

    clientManager.add(client);
    BOOST_REQUIRE_EQUAL(repo->getClients().size(), 1);
    clientManager.remove("1","2","3");
    BOOST_REQUIRE_EQUAL(repo->getClients().size(), 0);
}

BOOST_AUTO_TEST_CASE(ClientManagerChangePhoneNumberTest) {
    eventPtr event = make_shared<Tournament>();
    leaguePtr league = make_shared<LeagueA>();
    clientTypePtr clientType = make_shared<Club>(league);
    addressPtr address = make_shared<Address>("1", "2", "3");
    clientPtr client = make_shared<Client>(1, "123", "1234", address, clientType);
    clientRepositoryPtr repo = make_shared<ClientRepository>();
    ClientManager clientManager(repo);

    clientManager.add(client);
    clientManager.changePhoneNumber("4321","1","2","3");

    BOOST_REQUIRE_EQUAL(repo->get("1","2","3")->getPhoneNumber(), "4321");
}


BOOST_AUTO_TEST_SUITE_END()