//
// Created by student on 19.04.2022.
//

#include "model/Platinum.h"

int Platinum::getMaxVehicles() {
    return 5;
}

double Platinum::applyDiscount(double price) {
    return price * 0.1;
}

string Platinum::getTypeInfo() {
    return "platinum";
}
