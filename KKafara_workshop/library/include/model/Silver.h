//
// Created by student on 19.04.2022.
//

#ifndef CARRENTAL_SILVER_H
#define CARRENTAL_SILVER_H
#include "ClientType.h"



class Silver : public ClientType {
public:
    virtual int getMaxVehicles();
    virtual double applyDiscount(double price);
    virtual string getTypeInfo();
};


#endif //CARRENTAL_SILVER_H
