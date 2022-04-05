#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H
#include <string>

using namespace std;

class Address
{
private:
    string city;
    string street;
    string number;
public:
    Address(string city, string street, string number);

    string getAddressInfo();

    const string &getCity() const;
    void setCity(const string &city);

    const string &getStreet() const;
    void setStreet(const string &street);

    const string &getNumber() const;
    void setNumber(const string &number);
};

#endif //CARRENTAL_ADDRESS_H