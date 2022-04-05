#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include <string>
#include "Client.h"
#include "Vehicle.h"

using namespace std;

//class Client;

class Rent
{
private:
    unsigned int id;
    Client *client;
    Vehicle *vehicle;
public:
    string getRentInfo();

    Rent(unsigned int id, Client *client, Vehicle *vehicle);

    unsigned int getId() const;

    Client *getClient() const;

    Vehicle *getVehicle() const;
};

#endif //CARRENTAL_RENT_H
