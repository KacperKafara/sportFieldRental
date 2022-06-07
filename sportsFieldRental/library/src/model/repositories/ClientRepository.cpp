//
// Created by student on 04.06.2022.
//

#include "model/repositories/ClientRepository.h"
#include "model/Client.h"

void ClientRepository::add(clientPtr client) {
    for(auto c : clients) {
        if(c->getId() == client->getId()) return;
    }
    clients.push_back(client);
}

clientPtr ClientRepository::get(string city, string street, string number) {
    for(auto c : clients) {
        addressPtr adr = c -> getAddress();
        if(adr->getCity() == city && adr->getStreet() == street && adr -> getNumber() == number) {
            return c;
        }
    }
    return nullptr;
}

vector<clientPtr> &ClientRepository::getClients() {
    return clients;
}
