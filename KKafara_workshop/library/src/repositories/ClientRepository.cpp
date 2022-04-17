//
// Created by student on 11.04.2022.
//

#include "repositories/ClientRepository.h"

const clientPtr ClientRepository::get(int id) const {
    if(id >= 0 && size() > id)
        return clientRepository[id];
    return nullptr;
}

void ClientRepository::add(clientPtr client) {
    if(client != nullptr)
        clientRepository.push_back(client);
}

void ClientRepository::remove(clientPtr client) {
    if(client != nullptr)
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

vector<clientPtr> ClientRepository::findBy(ClientPredicate predicate) const {
    vector<clientPtr> found;
    for (unsigned int i = 0; i < clientRepository.size(); i++) {
        clientPtr client = get(i);
        if (client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    }
    return found;
}

bool returnTrue(clientPtr client)
{
    return true;
}

vector<clientPtr> ClientRepository::findAll() const {
    return findBy(returnTrue);
}