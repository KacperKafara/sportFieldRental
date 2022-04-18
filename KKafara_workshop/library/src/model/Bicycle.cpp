//
// Created by student on 17.04.2022.
//

#include "model/Bicycle.h"

Bicycle::Bicycle(const string &plateNumber, unsigned int basePrice) : Vehicle(plateNumber, basePrice) {}

double Bicycle::getActualRentalPrice() const {
    return Vehicle::getActualRentalPrice();
}
