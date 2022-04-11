#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include <string>
#include "Client.h"
#include "Vehicle.h"
#include <boost/date_time.hpp>

using namespace std;

using namespace boost::posix_time;

//class Client;

class Rent
{
private:
    unsigned int id;
    Client *client;
    Vehicle *vehicle;
    ptime beginTime;
    ptime endTime=not_a_date_time;

public:
    string getRentInfo();

    Rent(unsigned int id, Client *client, Vehicle *vehicle, ptime beginTime);

    unsigned int getId() const;

    Client *getClient() const;

    Vehicle *getVehicle() const;

    int getRentDays() const;

    int getRentCost() const;

    const ptime &getBeginTime() const;

    const ptime &getEndTime() const;

    void endRent(ptime time);
};

#endif //CARRENTAL_RENT_H
