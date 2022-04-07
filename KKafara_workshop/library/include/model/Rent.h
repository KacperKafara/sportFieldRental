//
// Created by student on 03.04.2022.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include <string>
#include <boost/date_time.hpp>

using std::string;
using namespace boost::posix_time;

class Client;
class Vehicle;

class Rent {
private:
    unsigned int id;
    Client *client;
    Vehicle *vehicle;
    ptime beginTime;
    ptime endTime = not_a_date_time;

public:
    Rent(unsigned int id, Client *client, Vehicle *vehicle, ptime time);

    unsigned int getId() const;
    Client *getClient() const;
    Vehicle *getVehicle() const;
    string getRentInfo();
    const ptime &getBeginTime() const;
    const ptime &getEndTime() const;
    void endRent(ptime &time);
    int getRentDays() const;
};

#endif //CARRENTAL_RENT_H
