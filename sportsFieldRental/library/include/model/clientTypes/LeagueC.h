//
// Created by student on 03.06.2022.
//

#ifndef SPORTSFIELDRENTAL_LEAGUEC_H
#define SPORTSFIELDRENTAL_LEAGUEC_H
#include "League.h"

class LeagueC : public League{
private:
    double discount = 0.1;
public:
    double getDiscount() const;
    string getLeague();
    string getLetter();
};


#endif //SPORTSFIELDRENTAL_LEAGUEC_H
