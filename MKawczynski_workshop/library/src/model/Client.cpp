#include <iostream>
#include "model/Client.h"

using namespace std;

Client::Client()
{
    cout<<"Konstruktor: Zostałem wywołany"<<endl;
}

Client::Client(string firstName, string lastName, string personalID) : firstName(firstName), lastName(lastName), personalID(personalID) {}

Client::~Client()
{
    cout<<"Dekonstruktor: Zostałem wywołany"<<endl;
}

string Client::getClientInfo()
{
    return firstName+" "+lastName+" "+personalID;
}