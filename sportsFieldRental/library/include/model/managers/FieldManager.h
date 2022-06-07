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
    FieldManager();
    void add(fieldPtr field);
    fieldPtr getFieldById(int id);
    const fieldRepositoryPtr &getFieldRepository() const;
};

#endif //SPORTSFIELDRENTAL_FIELDMANAGER_H
