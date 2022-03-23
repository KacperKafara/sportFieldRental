#include <iostream>
#include "model/Client.h"

using namespace std;

Client::Client()
{
    cout<<"Konstruktor: Zostałem wywołany"<<endl;
    Client::getClientInfo();
}

Client::Client(string firstName, string lastName, string personalID) : firstName(firstName), lastName(lastName), personalID(personalID)
{
    cout<<"Konstruktor: Zostałem wywołany"<<endl;
    cout<<getClientInfo()<<endl;
}

Client::~Client()
{
    cout<<"Dekonstruktor: Zostałem wywołany"<<endl;
    cout<<getClientInfo()<<endl;
}

string Client::getClientInfo()
{
    return firstName+" "+lastName+" "+personalID;
}