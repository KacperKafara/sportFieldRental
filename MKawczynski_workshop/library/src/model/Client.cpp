#include <iostream>
#include "model/Client.h"

using std::cout;
using std::string;
using std::endl;

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