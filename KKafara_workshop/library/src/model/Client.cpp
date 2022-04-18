//
// Created by student on 16.03.2022.
//

#include "typedefs.h"
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

Client::Client(const string &firstName, const string &lastName, const string &personalId, addressPtr address) : firstName(
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

void Client::setAddress(addressPtr address) {
    if(address)
        Client::address = address;
}

string Client::getClientInfo() const {
    string info =  "Client: " + firstName + " " + lastName + " " + personalID + " " + address->getAddressInfo();
    return info;
}