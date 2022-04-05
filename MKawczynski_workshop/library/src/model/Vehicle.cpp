#include "model/Vehicle.h"

using namespace std;

Vehicle::Vehicle(const string &plateNumber, unsigned int basePrice) : plateNumber(plateNumber), basePrice(basePrice) {}

string Vehicle::getVehicleInfo()
{
    return plateNumber+" "+to_string(basePrice);
}


const string &Vehicle::getPlateNumber() const {
    return plateNumber;
}
void Vehicle::setPlateNumber(const string &plateNumber) {
    if (plateNumber!="") {
        Vehicle::plateNumber = plateNumber;
    }
}

unsigned int Vehicle::getBasePrice() const {
    return basePrice;
}
void Vehicle::setBasePrice(unsigned int basePrice) {
    Vehicle::basePrice = basePrice;
}
