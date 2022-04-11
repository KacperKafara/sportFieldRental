//
// Created by student on 11.04.2022.
//

#include "repositories/StorageContainer.h"

using boost::posix_time::not_a_date_time;

ClientRepository &StorageContainer::getClientRepo() {
    return clientRepo;
}

RentRepository &StorageContainer::getRentRepo() {
    return rentRepo;
}

VehicleRepository &StorageContainer::getVehicleRepo() {
    return vehicleRepo;
}

StorageContainer::StorageContainer() {
    clientPtr client = new Client("Kacper", "Kafara", "242412", NULL);
    vehiclePtr vehicle = new Vehicle("WLS", 123);
    rentPtr rent = new Rent(1, client, vehicle, not_a_date_time);
    clientRepo.add(client);
    vehicleRepo.add(vehicle);
    rentRepo.add(rent);
}
