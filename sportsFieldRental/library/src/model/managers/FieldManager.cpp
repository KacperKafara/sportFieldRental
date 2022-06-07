//
// Created by student on 06.06.2022.
//

#include "model/managers/FieldManager.h"
#include "model/repositories/FieldRepository.h"
#include "model/Field.h"

void FieldManager::add(fieldPtr field){
    fieldRepository->add(field);
};

fieldPtr FieldManager::getFieldById(int id){
    return fieldRepository->get(id);
}

FieldManager::FieldManager() {
    fieldRepository = make_shared<FieldRepository>();
}

const fieldRepositoryPtr &FieldManager::getFieldRepository() const {
    return fieldRepository;
}
