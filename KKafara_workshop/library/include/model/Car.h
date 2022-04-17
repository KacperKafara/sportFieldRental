//
// Created by student on 17.04.2022.
//

#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H

#include "MotorVehicle.h"

class Car : public MotorVehicle {
private:
    enum SegmentType {
        A = 10,
        B = 11,
        C = 12,
        D = 13,
        E = 15
    };
public:
    Car(const string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement);
};


#endif //CARRENTAL_CAR_H
