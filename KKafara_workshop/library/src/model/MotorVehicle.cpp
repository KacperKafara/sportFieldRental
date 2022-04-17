//
// Created by student on 17.04.2022.
//

#include "model/MotorVehicle.h"

MotorVehicle::MotorVehicle(const string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement)
        : Vehicle(plateNumber, basePrice), engineDisplacement(engineDisplacement) {}
