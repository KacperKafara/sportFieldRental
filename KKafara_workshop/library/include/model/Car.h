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
    virtual double getActualRentalPrice() const;
    virtual string getVehicleInfo() const;
    virtual ~Car();
};


#endif //CARRENTAL_CAR_H
