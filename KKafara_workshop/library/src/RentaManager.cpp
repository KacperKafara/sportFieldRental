//
// Created by student on 21.04.2022.
//

#include "RentaManager.h"
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Vehicle.h"


vector<rentPtr> RentaManager::getAllClientRents(clientPtr client) const {
    return vector<rentPtr>();
}

rentPtr RentaManager::getVehicleRents(vehiclePtr vehicle) const {
    return rentPtr();
}

const double RentaManager::checkClientRentBalance(clientPtr client) const {
    return 0;
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
        if(currentRents.findAll()[i] == vehicle) {
            archiveRents.add(currentRents.findAll()[i]);
            currentRents.remove(currentRents.findAll()[i]);
        }
    }
}

