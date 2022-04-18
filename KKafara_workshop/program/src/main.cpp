#include <iostream>
#include "typedefs.h"
#include "repositories/StorageContainer.h"
#include "model/Car.h"

using namespace std;
using boost::posix_time::not_a_date_time;

int main() {
    Car car("WLS", 1000, 1000, SegmentType::C);
    cout << car.getVehicleInfo() << endl;
    return 0;
}
