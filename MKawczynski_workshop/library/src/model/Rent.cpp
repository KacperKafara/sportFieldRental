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
    string bt = ss.str();

    ss << endTime;
    string et = ss.str();

    return to_string(id)+" "+client->getClientInfo()+" "+vehicle->getVehicleInfo()+" "+bt+" "+et;
}

//int Rent::getRentDays()
//{
//    if (vehicle->isRented())
//    {
//        return 0;
//    }
//}

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

