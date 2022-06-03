//
// Created by student on 03.06.2022.
//

#include <string>
#include "model/Rent.h"

Rent::Rent(int id, const ptime &beginRentDate, const string &event) : id(id), beginRentDate(beginRentDate), event(event) {
//    if (beginRentDate.is_not_a_date_time()) {
//        &beginRentDate=second_clock::local_time();
//    }
}

int Rent::getId() const {
    return id;
}

const ptime &Rent::getBeginRentDate() const {
    return beginRentDate;
}

const ptime &Rent::getEndRentDate() const {
    return endRentDate;
}

const string &Rent::getEvent() const {
    return event;
}

void Rent::setEvent(const string &event) {
    Rent::event = event;
}

bool Rent::isArchive() const {
    return archive;
}

void Rent::makeArchive() {
    Rent::archive = true;
}

void Rent::endRent(ptime time) {
    if(endRentDate.is_not_a_date_time()) {
        endRentDate=time;
        if (endRentDate<beginRentDate) {
            endRentDate=beginRentDate;
        }
        if (endRentDate.is_not_a_date_time()) {
            endRentDate=second_clock::local_time();
        }
    }
}