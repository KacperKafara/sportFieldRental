//
// Created by student on 11.04.2022.
//

#include "repositories/ClientRepository.h"

const clientPtr ClientRepository::get(int id) const {
    return clientRepository[id];
}

void ClientRepository::add(clientPtr client) {
    if(client)
        clientRepository.push_back(client);
}

void ClientRepository::remove(clientPtr client) {
    if(client)
        clientRepository.erase(std::remove(clientRepository.begin(), clientRepository.end(), client), clientRepository.end());
}

const string ClientRepository::report() const {
    string info = "";
    for(int i = 0; i < clientRepository.size(); i++) {
        for(int j = 0; j < clientRepository[i]->getCurrentRents().size(); j++) {
            info = info + clientRepository[i]->getCurrentRents()[j]->getRentInfo() + "\n";
        }
    }
    return info;
}

const int ClientRepository::size() const {
    return clientRepository.size();
}
