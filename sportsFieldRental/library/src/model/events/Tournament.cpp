//
// Created by student on 03.06.2022.
//

#include "model/events/Tournament.h"

double Tournament::getDiscount() const {
    return discount;
}

string Tournament::getEventType() {
    return "Tournament";
}
