#include "model/Rent.h"

using namespace std;

Rent::Rent(unsigned int id, Client *client, Vehicle *vehicle, ptime beginTime) : id(id), client(client), vehicle(vehicle), beginTime(beginTime) {
    client->setCurrentRents(client->getCurrentRents(), this);
    vehicle->setRented(true);
    if(beginTime.is_not_a_date_time())
    {
        beginTime=second_clock::local_time();
    }
}

unsigned int Rent::getId() const {
    return id;
}

Client *Rent::getClient() const {
    return client;
}

Vehicle *Rent::getVehicle() const {
    return vehicle;
}

string Rent::getRentInfo()
{
    std::stringstream ss;
    ss << beginTime;
    string beginTimeString = ss.str();

    ss << endTime;
    string endTimeString = ss.str();

    return to_string(id)+" "+client->getClientInfo()+" "+vehicle->getVehicleInfo()+" "+beginTimeString+" "+endTimeString;
}

int Rent::getRentDays() const
{
    if (endTime.is_not_a_date_time())
    {
        return 0;
    }
    if(endTime-beginTime<=minutes(1))
    {
        return 0;
    }
    time_period beginOfRent=time_period(beginTime, second_clock::local_time());
    time_period endOfRent=time_period(endTime, second_clock::local_time());
    long hoursOfRent=beginOfRent.length().hours()-endOfRent.length().hours();
    int fullDay=1;
    fullDay+=(hoursOfRent/24);
    return fullDay;
}

int Rent::getRentCost() const
{
    return getRentDays()*vehicle->getBasePrice();
}

const ptime &Rent::getBeginTime() const {
    return beginTime;
}

const ptime &Rent::getEndTime() const {
    return endTime;
}

void Rent::endRent(ptime time)
{
    if(endTime.is_not_a_date_time())
    {
        endTime=time;
        if (endTime<beginTime)
        {
            endTime=beginTime;
        }
        if (endTime.is_not_a_date_time())
        {
            endTime=second_clock::local_time();
        }
    }
}

