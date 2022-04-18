//
// Created by student on 11.04.2022.
//

#include "repositories/VehicleRepository.h"
#include "model/Vehicle.h"
#include "model/Rent.h"

const vehiclePtr VehicleRepository::get(int id) const {
    if(id >= 0 && size() > id)
        return vehicleRepository[id];
    return nullptr;
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
//    for(int i = 0; i < vehicleRepository.size(); i++) {
//        bool veh = vehicleRepository[i]->isRented();
//        if(veh)
//            info = info + "Vehicle nr. " + std::to_string(i + 1) + " is rented\n";
//        else
//            info = info + "Vehicle nr. " + std::to_string(i + 1) + " is not rented\n";
//    }
    return info;
}

const int VehicleRepository::size() const {
    return vehicleRepository.size();
}

vector<vehiclePtr> VehicleRepository::findBy(VehiclePredicate predicate) const {
    vector<vehiclePtr> found;
    for (unsigned int i = 0; i < vehicleRepository.size(); i++) {
        vehiclePtr vehicle = get(i);
        if (vehicle != nullptr && predicate(vehicle)) {
            found.push_back(vehicle);
        }
    }
    return found;
}

bool returnTrue(vehiclePtr rent) {
    return true;
}

vector<vehiclePtr> VehicleRepository::findAll() const {
    return findBy(returnTrue);
}