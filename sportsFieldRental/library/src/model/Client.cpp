//
// Created by student on 02.06.2022.
//

#include <string>
#include "model/Client.h"

Client::Client(int id, const string &name, const string &phoneNumber, const addressPtr &address) : id(id), name(name),
                                                                                                   phoneNumber(
                                                                                                           phoneNumber),
                                                                                                   address(address) {}

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

//string Client::getInfo() {
//    return "Klient "+name+"\nTelefon "+phoneNumber+"\nAdres "+address->getInfo();
//}
