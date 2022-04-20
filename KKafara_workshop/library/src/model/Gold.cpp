//
// Created by student on 19.04.2022.
//

#include "model/Gold.h"

int Gold::getMaxVehicles() {
    return 4;
}

double Gold::applyDiscount(double price) {
    return price * 0.05;
}

string Gold::getTypeInfo() {
    return "gold";
}
