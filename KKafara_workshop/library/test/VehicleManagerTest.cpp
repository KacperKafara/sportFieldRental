//
// Created by student on 21.04.2022.
//

#include <boost/test/unit_test.hpp>
#include "VehicleManager.h"
#include "repositories/StorageContainer.h"
#include "model/Vehicle.h"

using namespace std;


BOOST_AUTO_TEST_SUITE(TestSuiteVehicleManager)

    BOOST_AUTO_TEST_CASE(VehicleManagerGetVehicleTest) {
        StorageContainer storage;
        VehicleManager vmanager(&storage.getVehicleRepo());
        BOOST_TEST(vmanager.getVehicle("WLS") == storage.getVehicleRepo().findAll()[0]);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerRegisterBicycleTest) {
        StorageContainer storage;
        VehicleManager vmanager(&storage.getVehicleRepo());
        BOOST_TEST(vmanager.registerBicycle("WLS", 123) == storage.getVehicleRepo().findByPlateNumber("WLS"));
        vmanager.registerBicycle("WLS1", 123);
        BOOST_TEST(storage.getVehicleRepo().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerRegisterMopedTest) {
        StorageContainer storage;
        VehicleManager vmanager(&storage.getVehicleRepo());
        BOOST_TEST(vmanager.registerMoped("WLS", 123, 123) == storage.getVehicleRepo().findByPlateNumber("WLS"));
        vmanager.registerMoped("WLS1", 123, 123);
        BOOST_TEST(storage.getVehicleRepo().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerRegisterCarTest) {
        StorageContainer storage;
        VehicleManager vmanager(&storage.getVehicleRepo());
        BOOST_TEST(vmanager.registerCar("WLS", 123, 123, SegmentType::A) == storage.getVehicleRepo().findByPlateNumber("WLS"));
        vmanager.registerCar("WLS1", 123, 123, SegmentType::B);
        BOOST_TEST(storage.getVehicleRepo().size() == 2);
    }

BOOST_AUTO_TEST_SUITE_END()