#include <iostream>
#include "model/Rent.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Vehicle.h"

using namespace std;
using boost::posix_time::not_a_date_time;

int main() {
    Address address("Warsaw", "Batorego", "24");
    Client client("Kacper", "Kafara", "242412", &address);
    Vehicle vehicle("WLS 12345", 123);
    Rent *rent = new Rent(1, &client, &vehicle, not_a_date_time);
    cout << client.getFullClientInfo() << endl;
    delete rent;
    return 0;
}
