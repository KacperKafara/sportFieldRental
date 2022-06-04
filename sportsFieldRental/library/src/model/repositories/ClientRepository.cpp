//
// Created by student on 04.06.2022.
//

#include "model/repositories/ClientRepository.h"
#include "model/Client.h"

void ClientRepository::add(clientPtr client) {
    for(auto c : clients) {
        if(c == client) return;
    }
    clients.push_back(client);
}

void ClientRepository::remove(string city, string street, string number) {
    for(int i = 0; i < clients.size(); i++) {
        addressPtr adr = clients[i] -> getAddress();
        if(adr->getCity() == city && adr->getStreet() == street && adr -> getNumber() == number) {
            clients.erase(clients.begin() + i);
        }
    }
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

const vector<clientPtr> &ClientRepository::getClients() const {
    return clients;
}
