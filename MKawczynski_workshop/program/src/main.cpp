#include <iostream>
#include "model/Client.h"

using namespace std;

int main()
{
    Client firstClient("ADAM","KRZYSZKOWIAK","2137");

    cout<<firstClient.getClientInfo()<<endl;

    Client *secondClient = new Client("ANIA","KASZOTTO","4423");

    cout<<secondClient->getClientInfo()<<endl;

    secondClient->setLastName("");

    cout<<secondClient->getClientInfo()<<endl;

    delete secondClient;

    return 0;
}