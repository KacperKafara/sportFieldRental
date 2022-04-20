//
// Created by student on 20.04.2022.
//

#include "ClientManager.h"
#include <iostream>
#include "model/Client.h"

clientPtr ClientManager::getClient(string Id) const {
    return cRepository->findByPersonalId(Id);
}

clientPtr ClientManager::registerClient(string firstName, string lastName, string personalId, addressPtr address,
                                        clientTypePtr clientType) {
    if(cRepository->findByPersonalId(personalId)) {
        return cRepository->findByPersonalId(personalId);
    }
    else {
        clientPtr client = std::make_shared<Client>(firstName, lastName, personalId, address, clientType);
        cRepository->add(client);
        return client;
    }
}

ClientManager::ClientManager(ClientRepository *cRepository) : cRepository(cRepository) {}

