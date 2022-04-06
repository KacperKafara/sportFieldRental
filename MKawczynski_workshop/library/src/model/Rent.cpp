#include "model/Rent.h"

using namespace std;

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

string Rent::getRentInfo()
{
    return to_string(id)+" "+client->getClientInfo()+" "+vehicle->getVehicleInfo();
}

