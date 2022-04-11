//
// Created by student on 11.04.2022.
//

#include "repositories/VehicleRepository.h"

const vehiclePtr VehicleRepository::get(int id) const {
    return vehicleRepository[id];
}

void VehicleRepository::add(vehiclePtr vehicle) {
    if(vehicle)
        vehicleRepository.push_back(vehicle);
}

void VehicleRepository::remove(vehiclePtr vehicle) {
    if(vehicle)
        vehicleRepository.erase(std::remove(vehicleRepository.begin(), vehicleRepository.end(), vehicle), vehicleRepository.end());
}

const string VehicleRepository::report() const {
    string info = "";
    for(int i = 0; i < vehicleRepository.size(); i++) {
        bool veh = vehicleRepository[i]->isRented();
        if(veh)
            info = info + "Vehicle nr. " + std::to_string(i + 1) + " is rented\n";
        else
            info = info + "Vehicle nr. " + std::to_string(i + 1) + " is not rented\n";
    }
    return info;
}

const int VehicleRepository::size() const {
    return vehicleRepository.size();
}
