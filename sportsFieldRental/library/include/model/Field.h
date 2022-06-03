//
// Created by student on 03.06.2022.
//

#ifndef SPORTSFIELDRENTAL_FIELD_H
#define SPORTSFIELDRENTAL_FIELD_H
#include <string>
#include "typedefs.h"
#include "Address.h"

using std::string;
using std::to_string;

class Field
{
private:
    int id;
    int tribuneCapacity;
    double baseCost;
    addressPtr address;
public:

    Field(int id, int tribuneCapacity, double baseCost, const addressPtr &address);

    double getBaseCost() const;

    int getTribuneCapacity() const;

    int getId() const;

    const addressPtr &getAddress() const;

    void setBaseCost(double cost);

    void setTribuneCapacity(int tribuneCapacity);

    string getInfo();
};

#endif //SPORTSFIELDRENTAL_FIELD_H
