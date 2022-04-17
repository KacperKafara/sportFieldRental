//
// Created by student on 11.04.2022.
//

#include <boost/test/unit_test.hpp>

#include "repositories/StorageContainer.h"

bool test(vehiclePtr vehicle) {
    return vehicle->getPlateNumber() == "WLS";
}

BOOST_AUTO_TEST_SUITE(TestSuiteVehicleRepository)

    BOOST_AUTO_TEST_CASE(VehicleRepositoryAddTest) {
        StorageContainer storage;
        BOOST_TEST_REQUIRE(storage.getVehicleRepo().size() == 1);
        vehiclePtr vehicle = new Vehicle("1234", 123);
        storage.getVehicleRepo().add(vehicle);
        BOOST_TEST(storage.getVehicleRepo().size() == 2);
        delete vehicle;
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryRemoveTest) {
        StorageContainer storage;
        vehiclePtr vehicle = new Vehicle("1234", 123);
        storage.getVehicleRepo().add(vehicle);
        storage.getVehicleRepo().remove(vehicle);
        BOOST_TEST(storage.getVehicleRepo().size() == 1);
        delete vehicle;
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryFindAllTest) {
        StorageContainer storage;
        vehiclePtr vehicle = new Vehicle("1234", 123);
        storage.getVehicleRepo().add(vehicle);
        BOOST_TEST(storage.getVehicleRepo().findAll().size() == 2);
        delete vehicle;
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryFindByTest) {
        StorageContainer storage;
        vehiclePtr vehicle = new Vehicle("1234", 123);
        storage.getVehicleRepo().add(vehicle);
        BOOST_TEST(storage.getVehicleRepo().findBy(test).at(0)->getPlateNumber().compare("WLS") == 0);
        delete vehicle;
    }


BOOST_AUTO_TEST_SUITE_END()