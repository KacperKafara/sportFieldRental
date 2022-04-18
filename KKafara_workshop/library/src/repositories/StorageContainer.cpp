//
// Created by student on 11.04.2022.
//

#include "repositories/StorageContainer.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Rent.h"
#include "model/Car.h"

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
    addressPtr address = new Address("Warsaw", "Batorego", "12");
    clientPtr client = new Client("Kacper", "Kafara", "242412", address);
    carPtr vehicle = new Car("WLS", 1000, 1000, SegmentType::A);
    rentPtr rent = new Rent(1, client, vehicle, not_a_date_time);
    clientRepo.add(client);
    vehicleRepo.add(vehicle);
    rentRepo.add(rent);
}
