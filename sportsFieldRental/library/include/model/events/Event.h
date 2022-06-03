//
// Created by student on 03.06.2022.
//

#ifndef SPORTSFIELDRENTAL_EVENT_H
#define SPORTSFIELDRENTAL_EVENT_H
#include <string>

using std::string;

class Event {
private:
    double discount = 0;
public:
    virtual double getDiscount() const;
    virtual string getEventInfo() = 0;
};


#endif //SPORTSFIELDRENTAL_EVENT_H
