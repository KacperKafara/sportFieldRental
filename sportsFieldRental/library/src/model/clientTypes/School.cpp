//
// Created by student on 02.06.2022.
//

#include "model/clientTypes/School.h"

School::School(double discount) : discount(discount) {}

string School::getType() {
    return "School";
}

double School::getDiscount() {
    return discount;
}
