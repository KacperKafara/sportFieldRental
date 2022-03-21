#include "model/Client.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Clinet::Client()
{
    cout<<"Konstruktor: Zostałem wywołany"<<endl;
}

Clinet::~Client()
{
    cout<<"Dekonstruktor: Zostałem wywołany"<<endl;
}

string Client::getClientInfo()
{
    return firstName+" "+lastName+" "+personaID;
}