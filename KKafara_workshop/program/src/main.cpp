#include <iostream>
#include "model/Client.h"

using namespace std;

int main() {
    Client c1;

    cout << c1.getClientInfo() << endl;

    Client *c2 = new Client;
    cout << c2->getClientInfo() << endl;
    delete c2;
    return 0;
}