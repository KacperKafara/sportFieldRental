//
// Created by student on 03.06.2022.
//

#ifndef SPORTSFIELDRENTAL_RENT_H
#define SPORTSFIELDRENTAL_RENT_H
#include <string>
#include "typedefs.h"
#include "model/Date.h"

using std::string;

class Rent {
private:
    int id;
    datePtr beginRentDate;
    datePtr endRentDate;
    eventPtr event;
    clientPtr client;
    fieldPtr field;
    bool archive=false;
public:
    Rent(int id, eventPtr event, clientPtr client, fieldPtr field, datePtr beginRentDate);
    int getId() const;
    const datePtr &getBeginRentDate() const;
    const datePtr &getEndRentDate() const;
    const string getEvent() const;
    void setEvent(eventPtr event);
    bool isArchive() const;
    void makeArchive();
    void endRent(datePtr time);
    const clientPtr &getClient() const;
    const fieldPtr &getField() const;
    int getRentHours() const;
    double getRentCost() const;
    string getInfo() const;
};

#endif //SPORTSFIELDRENTAL_RENT_H
