//
// Created by student on 20.04.2022.
//

#ifndef CARRENTAL_CLIENTMANAGER_H
#define CARRENTAL_CLIENTMANAGER_H
#include "repositories/StorageContainer.h"
#include "typedefs.h"
#include "vector"

class ClientManager {
private:
    ClientRepository *cRepository;
public:
    ClientManager(ClientRepository *cRepository);

    clientPtr getClient(string Id) const;
    clientPtr registerClient(string firstName, string lastName, string personalId, addressPtr address, clientTypePtr clientType);
    void unregisterClient(clientPtr client);
};


#endif //CARRENTAL_CLIENTMANAGER_H
