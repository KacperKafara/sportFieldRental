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
    Address(const string &city,const string &street,const string &number);
    string getAddressInfo();

    const string &getCity() const;

    const string &getStreet() const;

    void setCity(const string &city);

    void setStreet(const string &street);

    void setNumber(const string &number);

    const string &getNumber() const;
};


#endif //CARRENTAL_ADDRESS_H
