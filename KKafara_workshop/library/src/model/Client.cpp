//
// Created by student on 16.03.2022.
//

#include "model/Client.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;


Client::~Client() {

}

Client::Client(string fn, string ln, string id) : firstName(fn), lastName(ln), personalID(id){}

string Client::getClientInfo() {
    return firstName + " " + lastName + " " + personalID;
}

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
};
