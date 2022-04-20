//
// Created by student on 19.04.2022.
//

#include "model/Default.h"

int Default::getMaxVehicles(){
    return 1;
}

double Default::applyDiscount(double price){
    return 0;
}

string Default::getTypeInfo(){
    return "default";
}
