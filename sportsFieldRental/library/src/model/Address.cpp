//
// Created by student on 02.06.2022.
//

#include "model/Address.h"

Address::Address(const string &city, const string &street, const string &number) : city(city), street(street),
                                                                                   number(number) {}

const string &Address::getCity() const {
    return city;
}

const string &Address::getStreet() const {
    return street;
}

const string &Address::getNumber() const {
    return number;
}
