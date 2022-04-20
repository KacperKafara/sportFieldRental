//
// Created by student on 16.03.2022.
//

#include "typedefs.h"
#include "model/Client.h"
#include "model/Address.h"
#include "model/Rent.h"
#include "model/ClientType.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Client::Client(const string &firstName, const string &lastName, const string &personalId, addressPtr address, clientTypePtr clientType) : firstName(
        firstName), lastName(lastName), personalID(personalId), address(address), clientType(clientType) {};

const string &Client::getFirstName() const {
    return firstName;
}

const string &Client::getLastName() const {
    return lastName;
}

const string &Client::getPersonalId() const {
    return personalID;
}

void Client::setFirstName(const string &firstName) {
    if(firstName != "")
        Client::firstName = firstName;
}

void Client::setLastName(const string &lastName) {
    if(lastName != "")
        Client::lastName = lastName;
}

string Client::getClientInfo() const {
    string info =  "Client: " + firstName + " " + lastName + " " + personalID + " " + address->getAddressInfo() + " " + clientType -> getTypeInfo();
    return info;
}

const addressPtr &Client::getAddress() const {
    return address;
}

void Client::setAddress(const addressPtr &address) {
    Client::address = address;
}

void Client::setClientType(const clientTypePtr &clientType) {
    Client::clientType = clientTypePtr(clientType);
}

const int Client::getMaxVehicles() const {
    return clientType->getMaxVehicles();
}

const double Client::applyDiscount(double price) const {
    return clientType->applyDiscount(price);
}
