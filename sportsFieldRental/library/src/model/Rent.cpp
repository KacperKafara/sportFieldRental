//
// Created by student on 03.06.2022.
//

#include <string>
#include "model/Rent.h"
#include "model/events/Event.h"

Rent::Rent(int id, eventPtr event, clientPtr client, fieldPtr field, datePtr beginRentDate)
        : id(id), event(event), client(client), field(field), beginRentDate(beginRentDate) {
}

int Rent::getId() const {
    return id;
}

const datePtr &Rent::getBeginRentDate() const {
    return beginRentDate;
}

const datePtr &Rent::getEndRentDate() const {
    return endRentDate;
}

const string Rent::getEvent() const {
    return event->getEventType();
}

void Rent::setEvent(eventPtr event) {
    Rent::event = event;
}

bool Rent::isArchive() const {
    return archive;
}

void Rent::makeArchive() {
    Rent::archive = true;
}

void Rent::endRent(datePtr time) {
    if (isArchive()) {
        makeArchive();
        endRentDate = time;
    }
}

const clientPtr &Rent::getClient() const {
    return client;
}

const fieldPtr &Rent::getField() const {
    return field;
}

int Rent::getRentHours() const
{
    if (isArchive())
    {
        return endRentDate->hour-beginRentDate->hour;
    }
    else
    {
        return 0;
    }
}
