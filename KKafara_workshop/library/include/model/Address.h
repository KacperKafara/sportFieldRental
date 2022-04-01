//
// Created by student on 01.04.2022.
//

#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H
#include <string>
using std::string;

class Address {
private:
    string city, street, number;
public:
    Address(string city, string street, string number);
    string getAddressInfo(string city, string street, string number);

    const string &getCity() const;

    const string &getStreet() const;

    void setCity(const string &city);

    void setStreet(const string &street);

    void setNumber(const string &number);

    const string &getNumber() const;
};


#endif //CARRENTAL_ADDRESS_H
