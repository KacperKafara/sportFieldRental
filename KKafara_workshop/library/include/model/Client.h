//
// Created by student on 16.03.2022.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Rent;
class Address;

class Client {
private:
    string firstName;
    string lastName;
    string personalID;
    Address *address;
    vector<Rent*> currentRents;
public:
    Client(const string &firstName, const string &lastName, const string &personalId, Address *address);

    ~Client();
    const string &getFirstName() const;
    const string &getLastName() const;
    const string &getPersonalId() const;
    void setFirstName(const string &firstName);
    vector<Rent *> &getCurrentRents();
    void setAddress(Address *address);
    void setLastName(const string &lastName);
    Address *getAddress() const;
    string getClientInfo() const;
    string getFullClientInfo();
    void setCurrentRents(const vector<Rent *> &currentRents, Rent *rent);
};
#endif //CARRENTAL_CLIENT_H
