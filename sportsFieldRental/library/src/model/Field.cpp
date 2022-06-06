//
// Created by student on 03.06.2022.
//

#include <string>
#include "model/Field.h"

Field::Field(int id, int tribuneCapacity, double baseCost, const addressPtr &address) : id(id), tribuneCapacity(
        tribuneCapacity), baseCost(baseCost), address(address) {}

double Field::getBaseCost() const {
    return baseCost;
}

int Field::getTribuneCapacity() const {
    return tribuneCapacity;
}

int Field::getId() const {
    return id;
}

void Field::setBaseCost(double cost) {
    Field::baseCost = cost;
}

void Field::setTribuneCapacity(int tribuneCapacity) {
    Field::tribuneCapacity = tribuneCapacity;
}

const addressPtr &Field::getAddress() const {
    return address;
}

string Field::getInfo() {
    return "Id "+to_string(id)+"Adres "+address->getInfo()+"\nPojemność trybun "+ to_string(tribuneCapacity)+"\nKoszt bazowy "+to_string(baseCost);
}
