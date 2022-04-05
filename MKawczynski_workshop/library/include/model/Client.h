#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H
#include <string>
#include "Address.h"

using namespace std;

class Client
{
private:
    string firstName;
    string lastName;
    string personalID;
    Address *address;
    Client();
public:
    Client(string firstName, string lastName, string personalID, Address *address);
    ~Client();

    string getClientInfo();

    const string &getFirstName() const;
    void setFirstName(const string &firstName);

    const string &getLastName() const;
    void setLastName(const string &lastName);

    const string &getPersonalID() const;
    void setPersonalID(const string &personalID);

    const Address *getAddress() const;
    void setAddress(Address *address);
};

#endif //CARRENTAL_CLIENT_H