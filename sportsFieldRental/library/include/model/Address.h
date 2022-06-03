//
// Created by student on 02.06.2022.
//

#ifndef SPORTSFIELDRENTAL_ADDRESS_H
#define SPORTSFIELDRENTAL_ADDRESS_H
#include <string>

using std::string;

class Address {
private:
    string city;
    string street;
    string number;
public:
    Address(const string &city, const string &street, const string &number);

    const string &getCity() const;

    const string &getStreet() const;

    const string &getNumber() const;

    string getInfo();
};


#endif //SPORTSFIELDRENTAL_ADDRESS_H
