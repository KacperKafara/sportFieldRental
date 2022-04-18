//
// Created by student on 02.04.2022.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H

#include <string>

using std::string;

class Vehicle {
private:
    string plateNumber;
    unsigned int basePrice;
    bool rented = false;
public:
    Vehicle(const string &plateNumber, unsigned int basePrice);
    const string &getPlateNumber() const;
    void setPlateNumber(const string &plateNumber);
    unsigned int getBasePrice() const;
    void setBasePrice(unsigned int basePrice);
    virtual string getVehicleInfo() const;
    bool isRented() const;
    void setRented(bool rented);
    virtual double getActualRentalPrice() const;
    virtual ~Vehicle();
};


#endif //CARRENTAL_VEHICLE_H
