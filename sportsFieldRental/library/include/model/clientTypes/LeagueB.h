//
// Created by student on 03.06.2022.
//

#ifndef SPORTSFIELDRENTAL_LEAGUEB_H
#define SPORTSFIELDRENTAL_LEAGUEB_H
#include "League.h"

class LeagueB : public League{
private:
    double discount = 0.2;
public:
    double getDiscount() const;
    string getLeague();
};


#endif //SPORTSFIELDRENTAL_LEAGUEB_H
