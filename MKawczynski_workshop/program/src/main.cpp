#include <iostream>
#include "model/Client.h"

using namespace std;

int main()
{
    Client firstClient("ADAM","KRZYSZKOWIAK","2137");

    Client *secondClient = new Client("ANIA","KASZOTTO","4423");

    delete secondClient;

    return 0;
}