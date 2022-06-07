//
// Created by student on 02.06.2022.
//

#ifndef SPORTSFIELDRENTAL_SCHOOL_H
#define SPORTSFIELDRENTAL_SCHOOL_H
#include "ClientType.h"

class School : public ClientType {
private:
    double discount = 0;
public:
    string getType();
    double getDiscount();
    string getInfo();
    string getInfoForWriteToFile();
};


#endif //SPORTSFIELDRENTAL_SCHOOL_H
