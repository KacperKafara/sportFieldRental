//
// Created by student on 17.04.2022.
//

#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H

#include "Vehicle.h"

class MotorVehicle : public Vehicle{
private:
    unsigned int engineDisplacement;
public:
    MotorVehicle(const string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement);
    double getActualRentalPrice() const;
};


#endif //CARRENTAL_MOTORVEHICLE_H
