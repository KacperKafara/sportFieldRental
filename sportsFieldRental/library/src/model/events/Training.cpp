//
// Created by student on 03.06.2022.
//

#include "model/events/Training.h"

double Training::getDiscount() const {
    return discount;
}

string Training::getEventType() {
    return "Training";
}
