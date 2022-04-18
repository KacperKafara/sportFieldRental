#include <iostream>
#include "typedefs.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "repositories/StorageContainer.h"
#include "model/Bicycle.h"
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Address.h"

using namespace std;
using boost::posix_time::not_a_date_time;

int main() {
    StorageContainer storage;
    cout << storage.getClientRepo().report();
    cout << storage.getRentRepo().report();
    cout << storage.getVehicleRepo().report();
    cout << endl << endl;
    bicyclePtr bc = new Bicycle("WLS", 123);
    addressPtr ad = new Address("Warsaw", "Batorego", "13");
    clientPtr cl = new Client("Kacper", "Kafara", "242412", ad);
    rentPtr rent = new Rent(2, cl, bc, not_a_date_time);
    storage.getRentRepo().add(rent);
    cout << storage.getClientRepo().report();
    cout << storage.getRentRepo().report();
    cout << storage.getVehicleRepo().report();
    delete bc;
    delete ad;
    delete cl;
    delete rent;
    return 0;
}
