#include <iostream>
#include "model/Rent.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Vehicle.h"

using namespace std;

int main() {
    Address address("Warsaw", "Batorego", "24");
    Client client("Kacper", "Kafara", "242412", &address);
    Vehicle vehicle("WLS 12345", 123);
    Rent rent(1, &client, &vehicle);
    cout << client.getFullClientInfo() << endl;
    return 0;
}
