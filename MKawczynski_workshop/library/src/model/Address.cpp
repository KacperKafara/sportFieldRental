#include "model/Address.h"

using namespace std;

Address::Address(string city, string street, string number): city(city), street(street), number(number)
{
}

string Address::getAddressInfo()
{
    return city+" "+street+" "+number;
}


const string &Address::getCity() const
{
    return city;
}

void Address::setCity(const string &city)
{
    Address::city = city;
}


const string &Address::getStreet() const
{
    return street;
}

void Address::setStreet(const string &street)
{
    Address::street = street;
}


const string &Address::getNumber() const
{
    return number;
}

void Address::setNumber(const string &number)
{
    Address::number = number;
}

