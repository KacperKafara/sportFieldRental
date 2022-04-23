//
// Created by student on 19.04.2022.
//

#include "model/Diamond.h"

int Diamond::getMaxVehicles() {
    return 10;
}

double Diamond::applyDiscount(double price) {
    if(price < 125) return price * 0.1;
    else if(price < 250) return price * 0.2;
    else if(price < 500) return price * 0.3;
    return price * 0.4;
}

string Diamond::getTypeInfo() {
    return "diamond";
}
