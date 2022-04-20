#include <iostream>
#include "typedefs.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "repositories/StorageContainer.h"
#include "model/Bicycle.h"
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Address.h"
#include "model/Gold.h"
#include "ClientManager.h"

using namespace std;
using boost::posix_time::not_a_date_time;

int main() {
//    StorageContainer storage;
//    cout << storage.getClientRepo().report();
//    cout << storage.getRentRepo().report();
//    cout << storage.getVehicleRepo().report();
//    cout << endl << endl;
//    bicyclePtr bc = make_shared<Bicycle>("WLS", 123);
//    addressPtr ad = make_shared<Address>("Warsaw", "Batorego", "13");
//    clientTypePtr type = make_shared<Gold>();
//    clientPtr cl = make_shared<Client>("Kacper", "Kafara", "242412", ad, type);
//    rentPtr rent = make_shared<Rent>(2, cl, bc, not_a_date_time);
//    storage.getRentRepo().add(rent);
//    cout << storage.getClientRepo().report();
//    cout << storage.getRentRepo().report();
//    cout << storage.getVehicleRepo().report();
    StorageContainer storage;
    ClientManager clientManager(&storage.getClientRepo());
    clientManager.registerClient("Kacper1", "Kafara1", "1", nullptr, nullptr);
    cout << endl << storage.getClientRepo().size();

    return 0;
}
