#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"

using namespace std;

int main()
{
    Address address("Lodz","al.Politechniki","1");
    Client client("Jan","Kowalski","1",&address);

    Vehicle vehicle("1",10);

    Rent rent(1,&client,&vehicle);

    cout<<rent.getRentInfo();

    return 0;
}