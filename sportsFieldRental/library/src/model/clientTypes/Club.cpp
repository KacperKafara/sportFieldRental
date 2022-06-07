//
// Created by student on 02.06.2022.
//

#include "model/clientTypes/Club.h"
#include "model/clientTypes/League.h"

string Club::getType() {
    return "Club";
}

Club::Club(const leaguePtr &league) : league(league) {
    discount = league->getDiscount();
}

string Club::getInfo() {
    return "Typ: Klub, Liga: " + league->getLeague();
}

double Club::getDiscount() {
    return discount;
}

string Club::getInfoForWriteToFile() {
    return "Club " + league->getLetter();
}
