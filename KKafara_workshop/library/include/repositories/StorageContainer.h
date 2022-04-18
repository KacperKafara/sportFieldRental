//
// Created by student on 11.04.2022.
//

#ifndef CARRENTAL_STORAGECONTAINER_H
#define CARRENTAL_STORAGECONTAINER_H
#include "ClientRepository.h"
#include "RentRepository.h"
#include "VehicleRepository.h"

class StorageContainer {
private:
    ClientRepository clientRepo;
    RentRepository rentRepo;
    VehicleRepository vehicleRepo;
public:
    StorageContainer();
    ClientRepository &getClientRepo();
    RentRepository &getRentRepo();
    VehicleRepository &getVehicleRepo();
};


#endif //CARRENTAL_STORAGECONTAINER_H
