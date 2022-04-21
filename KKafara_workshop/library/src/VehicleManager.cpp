//
// Created by student on 21.04.2022.
//

#include "VehicleManager.h"

VehicleManager::VehicleManager(VehicleRepository *vehicleRepository) : vehicleRepository(vehicleRepository) {}

vehiclePtr VehicleManager::getVehicle(string plateNumber) {
    return vehicleRepository->findByPlateNumber(plateNumber);
}

vehiclePtr VehicleManager::registerBicycle(string plateNumber, unsigned int basePrice) {
    if(vehicleRepository->findByPlateNumber(plateNumber)){
        return vehicleRepository->findByPlateNumber(plateNumber);
    }
    else {
        vehiclePtr bicycle = std::make_shared<Bicycle>(plateNumber, basePrice);
        vehicleRepository->add(bicycle);
        return bicycle;
    }
}

vehiclePtr VehicleManager::registerMoped(string plateNumber, unsigned int basePrice, unsigned int engineDisplacement) {
    if(vehicleRepository->findByPlateNumber(plateNumber)){
        return  vehicleRepository->findByPlateNumber(plateNumber);
    }
    else {
        vehiclePtr moped = std::make_shared<Moped>(plateNumber, basePrice, engineDisplacement);
        vehicleRepository->add(moped);
        return moped;
    }
}

vehiclePtr VehicleManager::registerCar(string plateNumber, unsigned int basePrice, unsigned int engineDisplacement,
                                 SegmentType segment) {
    if(vehicleRepository->findByPlateNumber(plateNumber)){
        return  vehicleRepository->findByPlateNumber(plateNumber);
    }
    else {
        vehiclePtr car = std::make_shared<Car>(plateNumber, basePrice, engineDisplacement, segment);
        vehicleRepository->add(car);
        return car;
    }
}


