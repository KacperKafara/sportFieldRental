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
    vector<fieldPtr> &getFields();
    void add(fieldPtr field);
    fieldPtr get(int id);
};


#endif //SPORTSFIELDRENTAL_FIELDREPOSITORY_H
