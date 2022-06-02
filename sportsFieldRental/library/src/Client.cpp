//
// Created by student on 02.06.2022.
//

#include <string>
#include "Client.h"

Client::Client(int id, const string &name, const string &phoneNumber) : id(id), name(name), phoneNumber(phoneNumber) {}

int Client::getId() const {
    return id;
}

const string &Client::getName() const {
    return name;
}

const string &Client::getPhoneNumber() const {
    return phoneNumber;
}
