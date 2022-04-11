#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H

#include <string>

using namespace std;

class Vehicle
{
private:
    string plateNumber;
    unsigned int basePrice;
    bool rented=false;
public:
    Vehicle(const string &plateNumber, unsigned int basePrice);

    bool isRented() const;

    void setRented(bool rented);

    string getVehicleInfo();

    const string &getPlateNumber() const;
    void setPlateNumber(const string &plateNumber);

    unsigned int getBasePrice() const;
    void setBasePrice(unsigned int basePrice);
};

#endif //CARRENTAL_VECHICLE_H
