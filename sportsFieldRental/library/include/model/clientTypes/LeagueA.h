//
// Created by student on 03.06.2022.
//

#ifndef SPORTSFIELDRENTAL_LEAGUEA_H
#define SPORTSFIELDRENTAL_LEAGUEA_H
#include "League.h"

class LeagueA : public League{
private:
    double discount = 0.25;
public:
    string getLeague();
    double getDiscount() const;
    string getLetter();
};


#endif //SPORTSFIELDRENTAL_LEAGUEA_H
