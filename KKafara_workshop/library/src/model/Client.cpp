//
// Created by student on 16.03.2022.
//

#include "model/Client.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Client::Client() {
    cout << "Hello there!" << endl;
}

Client::~Client() {
    cout << "See you later!" << endl;
}

string Client::getClientInfo() {
    return firstName + " " + lastName + " " + personalID;
};
