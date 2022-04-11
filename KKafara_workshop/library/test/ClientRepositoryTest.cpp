//
// Created by student on 11.04.2022.
//

#include <boost/test/unit_test.hpp>

#include "repositories/StorageContainer.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClientRepository)

    BOOST_AUTO_TEST_CASE(ClientRepositoryAddTest) {
        StorageContainer storage;
        BOOST_TEST_REQUIRE(storage.getClientRepo().size() == 1);
        clientPtr client = new Client("Kacper1", "Kafara1", "242412",NULL);
        storage.getClientRepo().add(client);
        BOOST_TEST(storage.getClientRepo().size() == 2);
        delete client;
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryRemoveTest) {
        StorageContainer storage;
        clientPtr client = new Client("Kacper1", "Kafara1", "242412",NULL);
        storage.getClientRepo().add(client);
        storage.getClientRepo().remove(client);
        BOOST_TEST(storage.getClientRepo().size() == 1);
        delete client;
    }


BOOST_AUTO_TEST_SUITE_END()