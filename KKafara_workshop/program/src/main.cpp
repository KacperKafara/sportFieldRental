#include <iostream>
#include "model/Client.h"

using namespace std;

int main() {
    Client c1("Kacper1", "Kafara1", "242412!");
    

    Client *c2 = new Client("Kacper", "Kafara", "242412");
    delete c2;
    return 0;
}