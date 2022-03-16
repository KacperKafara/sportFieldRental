#include <iostream>
#include "model/Client.h"

using namespace std;

int main() {
    Client c1;

    Client *c2 = new Client;
    delete c2;
    return 0;
}