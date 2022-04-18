//
// Created by student on 16.03.2022.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include <string>
#include <vector>
#include "typedefs.h"

using std::string;
using std::vector;


class Client {
private:
    string firstName;
    string lastName;
    string personalID;
    addressPtr address;
public:
    Client(const string &firstName, const string &lastName, const string &personalId, addressPtr address);
    const string &getFirstName() const;
    const string &getLastName() const;
    const string &getPersonalId() const;
    void setFirstName(const string &firstName);
    void setLastName(const string &lastName);
    string getClientInfo() const;
    string getFullClientInfo();
    const addressPtr &getAddress() const;
    void setAddress(const addressPtr &address);
};
#endif //CARRENTAL_CLIENT_H
