//
// Created by student on 17.04.2022.
//

#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H

#include "MotorVehicle.h"
enum SegmentType {
    A = 10,
    B = 11,
    C = 12,
    D = 13,
    E = 15
};
class Car : public MotorVehicle {
private:
    SegmentType segment;
public:
    Car(const string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement, SegmentType segment);
    double getActualRentalPrice() const;
};


#endif //CARRENTAL_CAR_H
