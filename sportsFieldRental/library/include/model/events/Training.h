//
// Created by student on 03.06.2022.
//

#ifndef SPORTSFIELDRENTAL_TRAINING_H
#define SPORTSFIELDRENTAL_TRAINING_H
#include "Event.h"

class Training : public Event {
private:
    double discount = 0.15;
public:
    double getDiscount() const;
    string getEventInfo();
};


#endif //SPORTSFIELDRENTAL_TRAINING_H
