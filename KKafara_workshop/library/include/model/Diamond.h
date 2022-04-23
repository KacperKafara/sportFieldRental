//
// Created by student on 19.04.2022.
//

#ifndef CARRENTAL_DIAMOND_H
#define CARRENTAL_DIAMOND_H
#include "ClientType.h"


class Diamond : public ClientType {
public:
    virtual int getMaxVehicles();
    virtual double applyDiscount(double price);
    virtual string getTypeInfo();
};


#endif //CARRENTAL_DIAMOND_H
