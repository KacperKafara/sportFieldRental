#include <iostream>
#include "model/Client.h"
#include "model/Address.h"

using namespace std;

Client::Client()
{
}

Client::Client(string firstName, string lastName, string personalID, Address *address) : firstName(firstName), lastName(lastName), personalID(personalID), address(address)
{
}

Client::~Client()
{
}

string Client::getClientInfo()
{
    return firstName+" "+lastName+" "+personalID+address->getAddressInfo();
}

string Client::getFirstName()
{
    return firstName;
}

void Client::setFirstName(string firstName)
{
    if (firstName!="")
    {
        Client::firstName = firstName;
    }
}

string Client::getLastName()
{
    return lastName;
}

void Client::setLastName(string lastName)
{
    if (lastName!="")
    {
        Client::lastName = lastName;
    }
}

string Client::getPersonalID()
{
    return personalID;
}

void Client::setPersonalID(string personalID)
{
    if (personalID!="")
    {
        Client::personalID = personalID;
    }
}


Address *Client::getAddress()
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