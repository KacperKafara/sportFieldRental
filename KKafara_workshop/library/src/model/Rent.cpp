//
// Created by student on 03.04.2022.
//

#include "model/Rent.h"
#include "model/Client.h"
#include "model/Vehicle.h"

using std::stringstream;

Rent::Rent(unsigned int id, Client *client, Vehicle *vehicle, ptime time) : id(id), client(client), vehicle(vehicle), beginTime(time) {
    client->setCurrentRents(client->getCurrentRents(), this);
    vehicle->setRented(true);
    if(beginTime.is_not_a_date_time()) {
        beginTime = second_clock::local_time();
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

string Rent::getRentInfo() {
    stringstream ss;
    ss << beginTime;
    string s = ss.str();
    ss << endTime;
    string e = ss.str();
    return "Rent: " + std::to_string(id) + " " + client->getClientInfo() + " " + vehicle->getVehicleInfo() + " " + s + " " + e;
}

const ptime &Rent::getBeginTime() const {
    return beginTime;
}

const ptime &Rent::getEndTime() const {
    return endTime;
}

void Rent::endRent(ptime &time) {
    bool called = false;
    if(endTime.is_not_a_date_time()) {
        endTime = time;
    }
    if (time < beginTime && called == false) {
        endTime = beginTime;
        called = true;
    }

}
