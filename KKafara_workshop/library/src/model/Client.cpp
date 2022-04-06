//
// Created by student on 16.03.2022.
//

#include "model/Client.h"
#include "model/Address.h"
#include "model/Rent.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Client::~Client() {
//    delete address;
}

Client::Client(const string &firstName, const string &lastName, const string &personalId, Address *address) : firstName(
        firstName), lastName(lastName), personalID(personalId), address(address) {};

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

Address *Client::getAddress() const {
    return address;
}

void Client::setAddress(Address *address) {
    if(address)
        Client::address = address;
}

const vector<Rent *> &Client::getCurrentRents() const {
    return currentRents;
}

string Client::getClientInfo() const {
    string info =  "Client: " + firstName + " " + lastName + " " + personalID + " " + address->getAddressInfo();
    return info;
}

string Client::getFullClientInfo() {
    string info = getClientInfo() + " rentId: ";
    for(int i = 0; i < currentRents.size(); i++){
        info = info + std::to_string(currentRents[i] -> getId());
    }
    return info;
}

void Client::setCurrentRents(const vector<Rent *> &currentRents, Rent *rent) {
    Client::currentRents.push_back(rent);
}
