//
// Created by student on 20.04.2022.
//

#include <boost/test/unit_test.hpp>
#include "ClientManager.h"
#include "repositories/StorageContainer.h"
#include "model/Client.h"

using namespace std;


BOOST_AUTO_TEST_SUITE(TestSuiteClientManager)

    BOOST_AUTO_TEST_CASE(ClientManagerGetClientTest) {
        StorageContainer storage;
        ClientManager clientManager(&storage.getClientRepo());
        BOOST_TEST(clientManager.getClient("242412") == storage.getClientRepo().findAll()[0]);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerRegisterClientTest) {
        StorageContainer storage;
        ClientManager clientManager(&storage.getClientRepo());
        BOOST_TEST(clientManager.registerClient("Kacper1", "Kafara1", "242412", nullptr, nullptr) == clientManager.getClient("242412"));
        clientManager.registerClient("Kacper1", "Kafara1", "1", nullptr, nullptr);
        BOOST_TEST(storage.getClientRepo().size() == 2);
    }

BOOST_AUTO_TEST_SUITE_END()