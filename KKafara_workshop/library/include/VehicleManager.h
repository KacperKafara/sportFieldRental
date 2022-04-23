//
// Created by student on 21.04.2022.
//

#ifndef CARRENTAL_VEHICLEMANAGER_H
#define CARRENTAL_VEHICLEMANAGER_H
#include "repositories/VehicleRepository.h"
#include "model/Car.h"
#include "model/Bicycle.h"
#include "model/Moped.h"

class VehicleManager {
private:
    VehicleRepository *vehicleRepository;
public:
    VehicleManager(VehicleRepository *vehicleRepository);
    vehiclePtr getVehicle(string plateNumber);
    vehiclePtr registerBicycle(string plateNumber, unsigned int basePrice);
    vehiclePtr registerMoped(string plateNumber, unsigned int basePrice, unsigned int engineDisplacement);
    vehiclePtr registerCar(string plateNumber, unsigned int basePrice, unsigned int engineDisplacement, SegmentType segment);
};


#endif //CARRENTAL_VEHICLEMANAGER_H
