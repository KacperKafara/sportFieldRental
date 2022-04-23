//
// Created by student on 03.04.2022.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include <string>
#include "typedefs.h"
#include <boost/date_time.hpp>

using std::string;
using namespace boost::posix_time;

class Client;
class Vehicle;

class Rent {
private:
    unsigned int id;
    clientPtr client;
    vehiclePtr vehicle;
    ptime beginTime;
    ptime endTime = not_a_date_time;
    unsigned int rentCost = 0;

public:
    Rent(unsigned int id, clientPtr client, vehiclePtr vehicle, ptime time);

    unsigned int getId() const;
    string getRentInfo();
    void endRent(ptime &time);
    int getRentDays() const;
    int getRentCost() const;
    const clientPtr &getClient() const;
    const vehiclePtr &getVehicle() const;
    const ptime &getBeginTime() const;
    const ptime &getEndTime() const;
};

#endif //CARRENTAL_RENT_H
