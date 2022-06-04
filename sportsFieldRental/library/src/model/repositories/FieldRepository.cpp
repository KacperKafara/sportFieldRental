//
// Created by student on 04.06.2022.
//

#include "model/repositories/FieldRepository.h"
#include "model/Field.h"

const vector<fieldPtr> &FieldRepository::getFields() const {
    return fields;
}

void FieldRepository::add(fieldPtr field) {
    for(auto f : fields) {
        if(f->getId() == field->getId()) return;
    }
    fields.push_back(field);
}

void FieldRepository::remove(int id) {
    for(int i = 0; i < fields.size(); i++) {
        if(fields[i]->getId() == id) {
            fields.erase(fields.begin() + i);
        }
    }
}

fieldPtr FieldRepository::get(int id) {
    for(auto f : fields) {
        if(f->getId() == id) return f;
    }
    return nullptr;
}
