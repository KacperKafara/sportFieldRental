//
// Created by student on 19.04.2022.
//

#ifndef CARRENTAL_DEFAULT_H
#define CARRENTAL_DEFAULT_H
#include "ClientType.h"

class Default : public ClientType {
public:
    virtual int getMaxVehicles();
    virtual double applyDiscount(double price);
    virtual string getTypeInfo();
};


#endif //CARRENTAL_DEFAULT_H
