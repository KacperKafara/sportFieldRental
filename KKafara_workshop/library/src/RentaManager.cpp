//
// Created by student on 21.04.2022.
//

#include "RentaManager.h"
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Default.h"
#include "model/Bronze.h"
#include "model/Silver.h"
#include "model/Gold.h"
#include "model/Platinum.h"
#include "model/Diamond.h"

vector<rentPtr> RentaManager::getAllClientRents(clientPtr client) const {
    return vector<rentPtr>();
}

rentPtr RentaManager::getVehicleRents(vehiclePtr vehicle) const {
    return rentPtr();
}

const double RentaManager::checkClientRentBalance(clientPtr client) const {
    double balance = 0;
    for(int i = 0; i < archiveRents.size(); i++) {
        if(archiveRents.findAll()[i]->getClient() == client) {
            balance += archiveRents.findAll()[i]->getRentCost();
        }
    }
    return balance;
}

rentPtr RentaManager::rentVehicle(unsigned int id,clientPtr client, vehiclePtr vehicle) {
    for(int i = 0; i < currentRents.findAll().size(); i++){
        if(currentRents.findAll()[i]->getVehicle() == vehicle) return nullptr;
    }
    if(client->isArchive()) return nullptr;
    int numberOfRents = 0;
    for(int i = 0; i < currentRents.findAll().size(); i++){
        if(currentRents.findAll()[i]->getClient() == client) {
            numberOfRents++;
        }
    }
    if(numberOfRents < client->getMaxVehicles())
        return std::make_shared<Rent>(id, client, vehicle, boost::date_time::not_a_date_time);
    return nullptr;
}

void RentaManager::returnVehicle(vehiclePtr vehicle) {
    for(int i = 0; i < currentRents.findAll().size(); i++) {
        if(currentRents.findAll()[i]->getVehicle() == vehicle) {
            archiveRents.add(currentRents.findAll()[i]);
            currentRents.remove(currentRents.findAll()[i]);
        }
    }
}

void RentaManager::changeClientType(clientPtr client) {
    if(checkClientRentBalance(client) < 100) {
        clientTypePtr type = std::make_shared<Default>();
        client->setClientType(type);
    }
    else if(checkClientRentBalance(client) < 200) {
        clientTypePtr type = std::make_shared<Bronze>();
        client->setClientType(type);
    }
    else if(checkClientRentBalance(client) < 400) {
        clientTypePtr type = std::make_shared<Silver>();
        client->setClientType(type);
    }
    else if(checkClientRentBalance(client) < 800) {
        clientTypePtr type = std::make_shared<Gold>();
        client->setClientType(type);
    }
    else if(checkClientRentBalance(client) < 1600) {
        clientTypePtr type = std::make_shared<Platinum>();
        client->setClientType(type);
    }
    else {
        clientTypePtr type = std::make_shared<Diamond>();
        client->setClientType(type);
    }
}

