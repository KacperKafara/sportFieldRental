#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H
#include <string>
#include <vector>
#include "Address.h"
#include "Rent.h"

using namespace std;
using std::vector;

//class Rent;

class Client
{
private:
    string firstName;
    string lastName;
    string personalID;
    Address *address;
    vector<Rent*> currentRents;
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

    const vector<Rent*> &getCurrentRents() const;
    void setCurrentRents(const vector<Rent*> &currentRents, Rent *rent);
};

#endif //CARRENTAL_CLIENT_H