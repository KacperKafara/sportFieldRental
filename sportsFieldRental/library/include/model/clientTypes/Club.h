//
// Created by student on 02.06.2022.
//

#ifndef SPORTSFIELDRENTAL_CLUB_H
#define SPORTSFIELDRENTAL_CLUB_H
#include "ClientType.h"
#include "typedefs.h"

class Club : public ClientType {
private:
    double discount = 0;
    leaguePtr league;
public:
    Club(const leaguePtr &league);
    string getType();
    string getInfo();
    double getDiscount();
    string getInfoForWriteToFile();
};


#endif //SPORTSFIELDRENTAL_CLUB_H
