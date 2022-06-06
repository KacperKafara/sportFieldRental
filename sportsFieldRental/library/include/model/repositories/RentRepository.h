//
// Created by student on 04.06.2022.
//

#ifndef SPORTSFIELDRENTAL_RENTREPOSITORY_H
#define SPORTSFIELDRENTAL_RENTREPOSITORY_H
#include <vector>
#include "typedefs.h"
#include <string>

using std::vector;
using std::string;

class RentRepository {
private:
    vector<rentPtr> rents;
    vector<rentPtr> archiveRents;
public:
    RentRepository();

    void add(rentPtr rent);
    void makeArchive(int id, datePtr time);
    rentPtr get(int id);
    vector<rentPtr> get(string city, string street, string number);
    const vector<rentPtr> &getRents() const;
    const vector<rentPtr> &getArchiveRents() const;
};


#endif //SPORTSFIELDRENTAL_RENTREPOSITORY_H
