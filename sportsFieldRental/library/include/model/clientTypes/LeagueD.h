//
// Created by student on 03.06.2022.
//

#ifndef SPORTSFIELDRENTAL_LEAGUED_H
#define SPORTSFIELDRENTAL_LEAGUED_H
#include "League.h"

class LeagueD : public League{
private:
    double discount = 0.05;
public:
    double getDiscount() const;
    string getLeague();
};


#endif //SPORTSFIELDRENTAL_LEAGUED_H
