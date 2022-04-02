//
// Created by student on 01.04.2022.
//

#include "model/Address.h"

Address::Address(const string &city,const string &street,const string &number): city(city), street(street), number(number) {}

string Address::getAddressInfo() {
    return "Address: " + city + " " + street + " " + number;
}

const string &Address::getCity() const {
    return city;
}

const string &Address::getStreet() const {
    return street;
}

const string &Address::getNumber() const {
    return number;
}

void Address::setCity(const string &city) {
    Address::city = city;
}

void Address::setStreet(const string &street) {
    Address::street = street;
}

void Address::setNumber(const string &number) {
    Address::number = number;
}
