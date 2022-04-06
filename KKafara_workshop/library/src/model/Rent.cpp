//
// Created by student on 03.04.2022.
//

#include "model/Rent.h"
#include "model/Client.h"
#include "model/Vehicle.h"

Rent::Rent(unsigned int id, Client *client, Vehicle *vehicle) : id(id), client(client), vehicle(vehicle) {
    client->setCurrentRents(client->getCurrentRents(), this);
    vehicle->setRented(true);
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
    return "Rent: " + std::to_string(id) + " " + client->getClientInfo() + " " + vehicle->getVehicleInfo();
}
