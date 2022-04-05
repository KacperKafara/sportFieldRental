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

    string getFirstName();
    void setFirstName(string firstName);

    string getLastName();
    void setLastName(string lastName);

    string getPersonalID();
    void setPersonalID(string personalID);

    Address *getAddress();
    void setAddress(Address *address);
};

#endif //CARRENTAL_CLIENT_H