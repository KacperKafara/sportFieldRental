//
// Created by student on 16.03.2022.
//

#include "model/Client.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;


Client::~Client() {
    cout << "See you later! " << getClientInfo() << endl;
}

Client::Client(string fn, string ln, string id) : firstName(fn), lastName(ln), personalID(id){
    cout << "Constructor " << getClientInfo() << endl;
}

string Client::getClientInfo() {
    return firstName + " " + lastName + " " + personalID;
};
