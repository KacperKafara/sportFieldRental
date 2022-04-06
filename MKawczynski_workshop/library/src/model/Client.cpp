#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Rent.h"

using namespace std;

Client::Client(string firstName, string lastName, string personalID, Address *address) : firstName(firstName), lastName(lastName), personalID(personalID), address(address)
{
}

Client::~Client()
{
}

string Client::getClientInfo() {
    return firstName + " " + lastName + " " + personalID + " " + address->getAddressInfo();
}

string Client::getFullClientInfo()
{
//    string fullInfo=getClientInfo();
//    for(int i=0;i<currentRents.size();i++)
//    {
//        fullInfo+=" "+to_string(currentRents[i]->getId());
//    }
//    return fullInfo;
    return to_string(currentRents[0]->getId());
}

const string &Client::getFirstName() const
{
    return firstName;
}

void Client::setFirstName(const string &firstName)
{
    if (firstName!="")
    {
        Client::firstName = firstName;
    }
}

const string &Client::getLastName() const
{
    return lastName;
}

void Client::setLastName(const string &lastName)
{
    if (lastName!="")
    {
        Client::lastName = lastName;
    }
}

const string &Client::getPersonalID() const
{
    return personalID;
}

void Client::setPersonalID(const string &personalID)
{
    if (personalID!="")
    {
        Client::personalID = personalID;
    }
}


const Address *Client::getAddress() const
{
    return address;
}

void Client::setAddress(Address *address)
{
    if(address)
    {
        Client::address = address;
    }
}

const vector<Rent*> &Client::getCurrentRents() const {
    return currentRents;
}

void Client::setCurrentRents(const vector<Rent*> &currentRents, Rent *rent) {
    Client::currentRents.push_back(rent);
}
