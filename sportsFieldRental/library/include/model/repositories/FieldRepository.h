//
// Created by student on 04.06.2022.
//

#ifndef SPORTSFIELDRENTAL_FIELDREPOSITORY_H
#define SPORTSFIELDRENTAL_FIELDREPOSITORY_H
#include <vector>
#include "typedefs.h"
#include <string>

using std::vector;
using std::string;

class FieldRepository {
private:
    vector<fieldPtr> fields;
public:
    const vector<fieldPtr> &getFields() const;
    void add(fieldPtr field);
    void remove(int id);
    fieldPtr get(int id);
};


#endif //SPORTSFIELDRENTAL_FIELDREPOSITORY_H
