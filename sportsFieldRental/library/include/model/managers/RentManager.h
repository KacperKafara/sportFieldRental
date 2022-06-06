//
// Created by student on 06.06.2022.
//

#ifndef SPORTSFIELDRENTAL_RENTMANAGER_H
#define SPORTSFIELDRENTAL_RENTMANAGER_H

#include "typedefs.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class RentManager{
private:
    rentRepositoryPtr rentRepository;
public:
    RentManager();
    void begin(int id, eventPtr event, fieldPtr field, clientPtr client, datePtr beginRentDate);
    void end(int id, datePtr endRentDate);
    vector<rentPtr> getAllRentsForClient(string city, string street, string number);
    vector<rentPtr> getAllRentsForField(int fieldId);
    const rentRepositoryPtr &getRentRepository() const;
};

#endif //SPORTSFIELDRENTAL_RENTMANAGER_H
