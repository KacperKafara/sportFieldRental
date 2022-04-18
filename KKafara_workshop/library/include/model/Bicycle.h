//
// Created by student on 17.04.2022.
//

#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H

#include "Vehicle.h"

class Bicycle : public Vehicle {
public:
    Bicycle(const string &plateNumber, unsigned int basePrice);
    double getActualRentalPrice() const;
};


#endif //CARRENTAL_BICYCLE_H
