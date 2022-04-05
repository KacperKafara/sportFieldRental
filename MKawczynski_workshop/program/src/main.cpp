#include <iostream>
#include "model/Client.h"
#include "model/Address.h"

using namespace std;

int main()
{
    Address firstAddress("AAA","BBB","1");
    Address secondAddress("AAA","BBB","2");

    Client firstClient("ADAM","KRZYSZKOWIAK","2137",&firstAddress);

    cout<<firstClient.getClientInfo()<<endl;

    Client *secondClient = new Client("ANIA","KASZOTTO","4423",&secondAddress);

    cout<<secondClient->getClientInfo()<<endl;

    secondClient->setLastName("");

    cout<<secondClient->getClientInfo()<<endl;

    delete secondClient;

    return 0;
}