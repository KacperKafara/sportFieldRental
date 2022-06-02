//
// Created by student on 02.06.2022.
//

#ifndef SPORTSFIELDRENTAL_CLUB_H
#define SPORTSFIELDRENTAL_CLUB_H
#include "ClientType.h"

class Club : public ClientType {
private:
    double discount = 0;
public:
    string getType();
    Club();
};


#endif //SPORTSFIELDRENTAL_CLUB_H
