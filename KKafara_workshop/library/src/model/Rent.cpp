//
// Created by student on 03.04.2022.
//

#include "typedefs.h"
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Vehicle.h"

using std::stringstream;

Rent::Rent(unsigned int id, clientPtr client, vehiclePtr vehicle, ptime time) : id(id), client(client), vehicle(vehicle), beginTime(time) {
//    client->setCurrentRents(client->getCurrentRents(), this);
//    vehicle->setRented(true);
    if(beginTime.is_not_a_date_time()) {
        beginTime = second_clock::local_time();
    }
//    vehicle->setRented(true);
}

unsigned int Rent::getId() const {
    return id;
}

string Rent::getRentInfo() {
    stringstream ss;
    ss << beginTime;
    string s = ss.str();
    ss << endTime;
    string e = ss.str();
//    return "Rent: " + std::to_string(id) + " " + client->getFullClientInfo() + " " + vehicle->getVehicleInfo() + " " + s + " " + e;
    return "Rent: " + std::to_string(id) + " " + vehicle->getVehicleInfo() + " " + s + " " + e + "\n" + client -> getClientInfo();
}

void Rent::endRent(ptime &time) {
//    if(vehicle->isRented()) {
        if (endTime.is_not_a_date_time()) {
            endTime = time;
        }
        if (time < beginTime) {
            endTime = beginTime;
        }
//    }
//    vehicle->setRented(false);
//    client->getCurrentRents().erase(std::remove(client->getCurrentRents().begin(), client->getCurrentRents().end(), this),client->getCurrentRents().end());
    rentCost = getRentDays() * vehicle -> getBasePrice() - client -> applyDiscount(vehicle -> getBasePrice());
}

int Rent::getRentDays() const {
    if(endTime.is_not_a_date_time()) return 0;
    if((endTime - beginTime) <= minutes(1)) return 0;
    time_period b = time_period(beginTime, second_clock::local_time());
    time_period e = time_period(endTime, second_clock::local_time());
    long h = b.length().hours() - e.length().hours();
    int ct = 0;
    while(h - 24 >= 0)
    {
        ct++;
        h-=24;
    }
    ct++;
    return ct;
}

int Rent::getRentCost() const {
    return rentCost;
}

const clientPtr &Rent::getClient() const {
    return client;
}

const vehiclePtr &Rent::getVehicle() const {
    return vehicle;
}

const ptime &Rent::getBeginTime() const {
    return beginTime;
}

const ptime &Rent::getEndTime() const {
    return endTime;
}
