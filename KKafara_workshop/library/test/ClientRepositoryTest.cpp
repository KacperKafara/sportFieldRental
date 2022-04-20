//
// Created by student on 11.04.2022.
//

#include <boost/test/unit_test.hpp>

#include "repositories/StorageContainer.h"
#include "model/Client.h"

using std::make_shared;

bool test(clientPtr ptr) {
    return ptr->getFirstName().compare("Kacper") == 0;
}

BOOST_AUTO_TEST_SUITE(TestSuiteClientRepository)

    BOOST_AUTO_TEST_CASE(ClientRepositoryAddTest) {
        StorageContainer storage;
        BOOST_TEST_REQUIRE(storage.getClientRepo().size() == 1);
        clientPtr client = make_shared<Client>("Kacper1", "Kafara1", "242412", nullptr, nullptr);
        storage.getClientRepo().add(client);
        BOOST_TEST(storage.getClientRepo().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryRemoveTest) {
        StorageContainer storage;
        clientPtr client = make_shared<Client>("Kacper1", "Kafara1", "242412",nullptr, nullptr);
        storage.getClientRepo().add(client);
        storage.getClientRepo().remove(client);
        BOOST_TEST(storage.getClientRepo().size() == 1);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryFindAllTest) {
        StorageContainer storage;
        clientPtr client = make_shared<Client>("Kacper1", "Kafara1", "242412",nullptr, nullptr);
        storage.getClientRepo().add(client);
        BOOST_TEST(storage.getClientRepo().findAll().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryFindByTest) {
        StorageContainer storage;
        clientPtr client = make_shared<Client>("Kacper1", "Kafara1", "242412",nullptr, nullptr);
        storage.getClientRepo().add(client);
        BOOST_TEST(storage.getClientRepo().findBy(test).at(0)->getFirstName().compare("Kacper") == 0);
    }


BOOST_AUTO_TEST_SUITE_END()