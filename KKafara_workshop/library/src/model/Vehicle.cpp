//
// Created by student on 02.04.2022.
//

#include "model/Vehicle.h"

Vehicle::Vehicle(const string &plateNumber, unsigned int basePrice) : plateNumber(plateNumber), basePrice(basePrice) {}

const string &Vehicle::getPlateNumber() const {
    return plateNumber;
}

void Vehicle::setPlateNumber(const string &plateNumber) {
    if(plateNumber.compare("") != 0)
        Vehicle::plateNumber = plateNumber;
}

unsigned int Vehicle::getBasePrice() const {
    return basePrice;
}

void Vehicle::setBasePrice(unsigned int basePrice) {
    Vehicle::basePrice = basePrice;
}

string Vehicle::getVehicleInfo() const {
    return "Client " + plateNumber + " " + std::to_string(basePrice);
}

bool Vehicle::isRented() const {
    return rented;
}

void Vehicle::setRented(bool rented) {
    Vehicle::rented = rented;
}
