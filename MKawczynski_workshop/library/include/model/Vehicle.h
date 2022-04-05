#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H

#include <string>

using namespace std;

class Vehicle
{
private:
    string plateNumber;
    unsigned int basePrice;
public:
    Vehicle(const string &plateNumber, unsigned int basePrice);

    const string &getPlateNumber() const;
    void setPlateNumber(const string &plateNumber);

    unsigned int getBasePrice() const;
    void setBasePrice(unsigned int basePrice);
};

#endif //CARRENTAL_VECHICLE_H
