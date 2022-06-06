//
// Created by student on 06.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/managers/Manager.h"
#include "model/clientTypes/School.h"
#include "model/managers/ClientManager.h"
#include "model/managers/FieldManager.h"
#include "model/managers/RentManager.h"
#include "model/Client.h"
#include "model/Field.h"
#include "model/Rent.h"
#include "model/repositories/ClientRepository.h"
#include "model/repositories/FieldRepository.h"
#include "model/repositories/RentRepository.h"
#include "model/events/Training.h"
#include "model/Date.h"

BOOST_AUTO_TEST_SUITE(ManagerSuiteTest)

BOOST_AUTO_TEST_CASE(ManagerAddClientTest) {
    Manager manager;
    clientTypePtr type = make_shared<School>();
    manager.addClient(1, "Name", "123456789", "1", "2", "3", type);
    BOOST_REQUIRE_EQUAL(manager.getClientManager()->getClientByAddress("1", "2", "3")->getName(), "Name");
}

BOOST_AUTO_TEST_CASE(ManagerRemoveClientTest) {
    Manager manager;
    clientTypePtr type = make_shared<School>();
    manager.addClient(1, "Name", "123456789", "1", "2", "3", type);
    BOOST_REQUIRE_EQUAL(manager.getClientManager()->getClientRepository()->getClients().size(), 1);
    manager.removeClient("2", "3", "4");
    BOOST_REQUIRE_EQUAL(manager.getClientManager()->getClientRepository()->getClients().size(), 1);
    manager.removeClient("1", "2", "3");
    BOOST_REQUIRE_EQUAL(manager.getClientManager()->getClientRepository()->getClients().size(), 0);
}

BOOST_AUTO_TEST_CASE(ManagerChangePhoneNumberTest) {
    Manager manager;
    clientTypePtr type = make_shared<School>();
    manager.addClient(1, "Name", "123456789", "1", "2", "3", type);
    BOOST_REQUIRE_EQUAL(manager.getClientByAddress("1", "2", "3")->getPhoneNumber(), "123456789");
    manager.changeClientPhoneNumber("012345678", "1", "2", "3");
    BOOST_REQUIRE_EQUAL(manager.getClientByAddress("1", "2", "3")->getPhoneNumber(), "012345678");
}

BOOST_AUTO_TEST_CASE(ManagerAddFieldTest) {
    Manager manager;
    manager.addField(1, "1", "2", "3", 2000, 300);
    BOOST_REQUIRE_EQUAL(manager.getFieldManager()->getFieldById(1)->getTribuneCapacity(), 2000);
}

BOOST_AUTO_TEST_CASE(ManagerRemoveFieldTest) {
    Manager manager;
    manager.addField(1, "1", "2", "3", 2000, 300);
    BOOST_REQUIRE_EQUAL(manager.getFieldManager()->getFieldRepository()->getFields().size(), 1);
    manager.removeField(2);
    BOOST_REQUIRE_EQUAL(manager.getFieldManager()->getFieldRepository()->getFields().size(), 1);
    manager.removeField(1);
    BOOST_REQUIRE_EQUAL(manager.getFieldManager()->getFieldRepository()->getFields().size(), 0);
}

BOOST_AUTO_TEST_CASE(ManagerStartEndRentTest) {
    Manager manager;
    clientTypePtr type = make_shared<School>();
    eventPtr event = make_shared<Training>();
    datePtr dateStart = make_shared<Date>(2020,1,1,12,1);
    datePtr dateEnd = make_shared<Date>(2020,1,1,12,1);
    manager.addClient(1, "Name", "123456789", "1", "2", "3", type);
    manager.addField(1, "2", "3", "4", 2000, 300);
    manager.startRent(1, event, manager.getFieldById(1), manager.getClientByAddress("1", "2", "3"), dateStart);
    BOOST_REQUIRE_EQUAL(manager.getRentManager()->getRentRepository()->getRents().size(), 1);
    BOOST_REQUIRE_EQUAL(manager.getRentManager()->getRentRepository()->getArchiveRents().size(), 0);
    manager.endRent(1, dateEnd);
    BOOST_REQUIRE_EQUAL(manager.getRentManager()->getRentRepository()->getRents().size(), 0);
    BOOST_REQUIRE_EQUAL(manager.getRentManager()->getRentRepository()->getArchiveRents().size(), 1);
}

BOOST_AUTO_TEST_CASE(ManagerGetAllRentsForTest) {
    Manager manager;
    clientTypePtr type = make_shared<School>();
    eventPtr event = make_shared<Training>();
    datePtr dateStart = make_shared<Date>(2020,1,1,12,1);
    datePtr dateEnd = make_shared<Date>(2020,1,1,12,1);
    manager.addClient(1, "Name", "123456789", "1", "2", "3", type);
    manager.addField(1, "2", "3", "4", 2000, 300);
    manager.startRent(1, event, manager.getFieldById(1), manager.getClientByAddress("1", "2", "3"), dateStart);
    BOOST_REQUIRE_EQUAL(manager.getAllRentsForField(1)[0]->getField()->getBaseCost(), 300);
    BOOST_REQUIRE_EQUAL(manager.getAllRentsForClient("1", "2", "3")[0]->getClient()->getName(), "Name");
    BOOST_REQUIRE_EQUAL(manager.getAllRentsForField(2).size(), 0);
    BOOST_REQUIRE_EQUAL(manager.getAllRentsForClient("1", "2", "4").size(), 0);
}

BOOST_AUTO_TEST_SUITE_END()