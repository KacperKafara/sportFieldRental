//
// Created by student on 19.04.2022.
//

#ifndef CARRENTAL_PLATINUM_H
#define CARRENTAL_PLATINUM_H
#include "ClientType.h"


class Platinum : public ClientType {
public:
    virtual int getMaxVehicles();
    virtual double applyDiscount(double price);
    virtual string getTypeInfo();
};


#endif //CARRENTAL_PLATINUM_H
