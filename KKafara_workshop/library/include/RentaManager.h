//
// Created by student on 21.04.2022.
//

#ifndef CARRENTAL_RENTAMANAGER_H
#define CARRENTAL_RENTAMANAGER_H
#include "typedefs.h"
#include "repositories/RentRepository.h"
#include <vector>
#include <memory>

class RentaManager {
private:
    RentRepository currentRents;
    RentRepository archiveRents;
public:
    vector<rentPtr> getAllClientRents(clientPtr client) const;
    rentPtr getVehicleRents(vehiclePtr vehicle) const;
    const double checkClientRentBalance(clientPtr client) const;
    rentPtr rentVehicle(unsigned int id,clientPtr client, vehiclePtr vehicle);
    void returnVehicle(vehiclePtr vehicle);
    void changeClientType(clientPtr client);
};


#endif //CARRENTAL_RENTAMANAGER_H
