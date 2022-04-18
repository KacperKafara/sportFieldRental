//
// Created by student on 11.04.2022.
//

#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H

//#include "model/Client.h"
//#include "model/Address.h"
//#include "model/Rent.h"
//#include "model/Vehicle.h"
//#include "model/Car.h"
//#include "model/Bicycle.h"
//#include "model/Moped.h"

class Client;
class Address;
class Rent;
class Vehicle;
class Car;
class Bicycle;
class Moped;

typedef Client *clientPtr;
typedef Address *addressPtr;
typedef Rent *rentPtr;
typedef Vehicle *vehiclePtr;
typedef Car *carPtr;
typedef Bicycle *bicyclePtr;
typedef Moped *mopedPtr;

typedef bool (*ClientPredicate)(clientPtr);
typedef bool (*VehiclePredicate)(vehiclePtr);
typedef bool (*RentPredicate)(rentPtr);


#endif //CARRENTAL_TYPEDEFS_H
