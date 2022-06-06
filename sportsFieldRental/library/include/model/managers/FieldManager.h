//
// Created by student on 06.06.2022.
//

#ifndef SPORTSFIELDRENTAL_FIELDMANAGER_H
#define SPORTSFIELDRENTAL_FIELDMANAGER_H

#include "typedefs.h"
#include <string>

using std::string;

class FieldManager{
private:
    fieldRepositoryPtr fieldRepository;
public:
    FieldManager(const fieldRepositoryPtr &fieldRepository);

    void add(fieldPtr field);
    void remove(int id);
    fieldPtr getFieldById(int id);
};

#endif //SPORTSFIELDRENTAL_FIELDMANAGER_H
