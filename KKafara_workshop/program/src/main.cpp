#include <iostream>
#include "model/Client.h"

using namespace std;

int main() {
    Address address("Warsaw", "Batorego", "24");
    Client client1("Kacper", "Kafara", "242412", &address);
    Client client2("Kacper1", "Kafara1", "131323", &address);
    Address *adr = client1.getAddress();
    adr->setCity("Lodz");
    cout << client1.getClientInfo() << endl;
    cout << client2.getClientInfo() << endl;
    return 0;
}
