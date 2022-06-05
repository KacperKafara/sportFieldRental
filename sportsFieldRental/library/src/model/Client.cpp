//
// Created by student on 02.06.2022.
//

#include <string>
#include "model/Client.h"
#include "model/clientTypes/ClientType.h"


int Client::getId() const {
    return id;
}

const string &Client::getName() const {
    return name;
}

const string &Client::getPhoneNumber() const {
    return phoneNumber;
}

const addressPtr &Client::getAddress() const {
    return address;
}

Client::Client(int id, const string &name, const string &phoneNumber, const addressPtr &address,
               const clientTypePtr &clientType) : id(id), name(name), phoneNumber(phoneNumber), address(address),
                                                  clientType(clientType) {}

const clientTypePtr &Client::getClientType() const {
    return clientType;
}

const string Client::getType() const {
    return clientType->getType();
}

const string Client::getInfo() const {
    return "Klient ID "+std::to_string(id)+"\nTyp "+getType()+"\nAdres "+getAddress()->getInfo()+"\nNumer telefonu "+phoneNumber;
}