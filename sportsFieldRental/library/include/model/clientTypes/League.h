//
// Created by student on 02.06.2022.
//

#ifndef SPORTSFIELDRENTAL_LEAGUE_H
#define SPORTSFIELDRENTAL_LEAGUE_H
#include <string>

using std::string;

class League {
private:
    double discount = 0;
public:
    virtual string getLeague() = 0;
    virtual double getDiscount() const;
    virtual string getLetter() = 0;
};


#endif //SPORTSFIELDRENTAL_LEAGUE_H
