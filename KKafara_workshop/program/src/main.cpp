#include <iostream>
#include "model/Client.h"

using namespace std;

int main() {
    Client c1("Kacper", "Kafara1", "242412!");


    Client *c2 = new Client("Kacper", "Kafara", "242412");
    c2->setFirstName("");
    cout << c2->getClientInfo() << endl;
    delete c2;
    return 0;
}