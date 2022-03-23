#include <iostream>
#include "model/Client.h"

using namespace std;

int main()
{
    Client firstClient;

    cout<<firstClient.getClientInfo()<<endl;

    Client *secondClient=new Client;

    cout<<secondClient->getClientInfo()<<endl;

    delete secondClient;

    return 0;
}