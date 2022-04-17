//
// Created by student on 11.04.2022.
//

#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H

#include "model/Client.h"
#include "model/Address.h"
#include "model/Rent.h"
#include "model/Vehicle.h"

typedef Client *clientPtr;
typedef Address *addressPtr;
typedef Rent *rentPtr;
typedef Vehicle *vehiclePtr;

typedef bool (*ClientPredicate)(clientPtr);
typedef bool (*VehiclePredicate)(vehiclePtr);
typedef bool (*RentPredicate)(rentPtr);


#endif //CARRENTAL_TYPEDEFS_H
