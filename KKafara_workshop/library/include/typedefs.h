//
// Created by student on 11.04.2022.
//

#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H

#include <memory>

using std::shared_ptr;
using std::unique_ptr;

class Client;
class Address;
class Rent;
class Vehicle;
class Car;
class Bicycle;
class Moped;
class ClientType;
class Default;


typedef shared_ptr<Client> clientPtr;
typedef shared_ptr<Address> addressPtr;
typedef shared_ptr<Rent> rentPtr;
typedef shared_ptr<Vehicle> vehiclePtr;
typedef shared_ptr<Car> carPtr;
typedef shared_ptr<Bicycle> bicyclePtr;
typedef shared_ptr<Moped> mopedPtr;
typedef shared_ptr<ClientType> clientTypePtr;

typedef bool (*ClientPredicate)(clientPtr);
typedef bool (*VehiclePredicate)(vehiclePtr);
typedef bool (*RentPredicate)(rentPtr);
typedef bool (*ClientManagerPredictate)(clientPtr);


#endif //CARRENTAL_TYPEDEFS_H
