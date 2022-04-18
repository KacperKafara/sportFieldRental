//
// Created by student on 17.04.2022.
//

#include "model/Car.h"
#include <math.h>

Car::Car(const string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement, SegmentType segment)
        : MotorVehicle(plateNumber, basePrice, engineDisplacement), segment(segment) {}

double Car::getActualRentalPrice() const {
    return round(MotorVehicle::getActualRentalPrice() * ((double)segment / 10));
}

string Car::getVehicleInfo() const {
    return MotorVehicle::getVehicleInfo() + " Segment: " + std::to_string((double)segment / 10);
}

Car::~Car() {}

