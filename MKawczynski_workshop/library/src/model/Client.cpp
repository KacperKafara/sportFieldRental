#include <iostream>
#include "model/Client.h"

using std::cout;
using std::string;
using std::endl;

Client::Client()
{
    cout<<"Konstruktor: Zostałem wywołany"<<endl;
}

Client::~Client()
{
    cout<<"Dekonstruktor: Zostałem wywołany"<<endl;
}

string Client::getClientInfo()
{
    return firstName+" "+lastName+" "+personalID;
}