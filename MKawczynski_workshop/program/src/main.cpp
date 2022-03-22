#include <iostream>
#include "Client.h"
#include "model/Client.h"

using namespace std;

int main()
{
    Client firstClient;

    cout<<firstClient.clientGetInfo()<<endl;

    Client *secondClient=new Client;

    cout<<secondClient->clientGetInfo()<<endl;

    delete secondClient;

    return 0;
}