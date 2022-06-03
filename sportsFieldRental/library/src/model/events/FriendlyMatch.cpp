//
// Created by student on 03.06.2022.
//

#include "model/events/FriendlyMatch.h"

double FriendlyMatch::getDiscount() const {
    return discount;
}

string FriendlyMatch::getEventType() {
    return "Friendly Match";
}
