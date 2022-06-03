//
// Created by student on 03.06.2022.
//

#ifndef SPORTSFIELDRENTAL_FRIENDLYMATCH_H
#define SPORTSFIELDRENTAL_FRIENDLYMATCH_H
#include "Event.h"

class FriendlyMatch : public Event {
private:
    double discount = 0.05;
public:
    double getDiscount() const;
    string getEventInfo();
};


#endif //SPORTSFIELDRENTAL_FRIENDLYMATCH_H
