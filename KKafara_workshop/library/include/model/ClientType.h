//
// Created by student on 19.04.2022.
//

#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H
#include <string>

using std::string;

class ClientType {
public:
    virtual int getMaxVehicles() = 0;
    virtual double applyDiscount(double price) = 0;
    virtual string getTypeInfo() = 0;
};


#endif //CARRENTAL_CLIENTTYPE_H
