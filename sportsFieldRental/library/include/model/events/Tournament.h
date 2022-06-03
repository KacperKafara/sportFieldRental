//
// Created by student on 03.06.2022.
//

#ifndef SPORTSFIELDRENTAL_TOURNAMENT_H
#define SPORTSFIELDRENTAL_TOURNAMENT_H
#include "Event.h"

using std::string;

class Tournament : public Event {
private:
    double discount = 0.1;
public:
    double getDiscount() const;
    string getEventType();
};


#endif //SPORTSFIELDRENTAL_TOURNAMENT_H
