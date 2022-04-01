#include <iostream>
#include "model/Client.h"

using namespace std;

int main() {
    Client *client = new Client("Kacper", "Kafara", "242412", NULL);
    Address *address = new Address("Warsaw", "Batorego", "24");
    client->setAddress(address);
    cout << client->getClientInfo() << endl;
    delete client;
    cout << address->getAddressInfo() << endl;
    return 0;
}
