//
// Created by student on 03.06.2022.
//

#include <string>
#include "model/Field.h"

Field::Field(int id, int tribuneCapacity, double baseCost, const addressPtr &address) : id(id), tribuneCapacity(
        tribuneCapacity), baseCost(baseCost), address(address) {
    if(id<1)
    {
        //throw std::invalid_argument("Invalid argument ID cannot be less than 1");
    }
    if(tribuneCapacity<1)
    {
        throw std::invalid_argument("Invalid argument tribune capacity cannot be less than 1");
    }
    if(baseCost<0)
    {
        //throw std::invalid_argument("Invalid argument base cost cannot be less than 0");
    }
}

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
    return "Id "+to_string(id)+"\nAdres "+address->getInfo()+"\nPojemność trybun "+ to_string(tribuneCapacity)+"\nKoszt bazowy "+to_string(baseCost);
}
