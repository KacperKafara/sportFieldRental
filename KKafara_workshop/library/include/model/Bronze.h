//
// Created by student on 19.04.2022.
//

#ifndef CARRENTAL_BRONZE_H
#define CARRENTAL_BRONZE_H
#include "ClientType.h"


class Bronze : public ClientType {
public:
    virtual int getMaxVehicles();
    virtual double applyDiscount(double price);
    virtual string getTypeInfo();
};


#endif //CARRENTAL_BRONZE_H
