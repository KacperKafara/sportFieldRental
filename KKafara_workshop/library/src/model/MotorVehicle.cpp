//
// Created by student on 17.04.2022.
//

#include "model/MotorVehicle.h"

MotorVehicle::MotorVehicle(const string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement)
        : Vehicle(plateNumber, basePrice), engineDisplacement(engineDisplacement) {}

double MotorVehicle::getActualRentalPrice() const {
    if(engineDisplacement < 1000)
        return Vehicle::getActualRentalPrice();
    else if(engineDisplacement >= 1000 && engineDisplacement <= 2000) {
        return (0.0005 * engineDisplacement + 0.5) * Vehicle::getActualRentalPrice();
    }
    else
        return Vehicle::getActualRentalPrice() * 1.5;
}
