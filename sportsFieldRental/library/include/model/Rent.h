//
// Created by student on 03.06.2022.
//

#ifndef SPORTSFIELDRENTAL_RENT_H
#define SPORTSFIELDRENTAL_RENT_H
#include <string>
#include "typedefs.h"
#include <boost/date_time.hpp>

using std::string;
using namespace boost::posix_time;

class Rent
{
private:
    int id;
    ptime beginRentDate;
    ptime endRentDate=not_a_date_time;
    string event;
    bool archive=false;
public:
    Rent(int id, const ptime &beginRentDate, const string &event);

    int getId() const;

    const ptime &getBeginRentDate() const;

    const ptime &getEndRentDate() const;

    const string &getEvent() const;

    void setEvent(const string &event);

    bool isArchive() const;

    void makeArchive();

    void endRent(ptime time);


};

#endif //SPORTSFIELDRENTAL_RENT_H
