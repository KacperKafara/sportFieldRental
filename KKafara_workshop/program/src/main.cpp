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
    Vehicle vehicle1("1234", 1234);
    Rent *rent = new Rent(1, &client, &vehicle, not_a_date_time);
//    ptime t1 = ptime(boost::gregorian::date(2023,5,13),hours(9)+minutes(25));
    ptime t2 = rent->getBeginTime() + hours(48);
    rent->endRent(t2);
    cout << client.getFullClientInfo() << endl;
    cout << rent->getRentDays() << endl;
    delete rent;
    return 0;
}
