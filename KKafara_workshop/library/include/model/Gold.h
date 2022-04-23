//
// Created by student on 19.04.2022.
//

#ifndef CARRENTAL_GOLD_H
#define CARRENTAL_GOLD_H
#include "ClientType.h"



class Gold : public ClientType {
public:
    virtual int getMaxVehicles();
    virtual double applyDiscount(double price);
    virtual string getTypeInfo();
};


#endif //CARRENTAL_GOLD_H
