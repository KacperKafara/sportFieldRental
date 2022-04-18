//
// Created by student on 17.04.2022.
//

#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H

#include "MotorVehicle.h"

class Moped : public MotorVehicle {
public:
    Moped(const string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement);
    double getActualRentalPrice() const;
};


#endif //CARRENTAL_MOPED_H
