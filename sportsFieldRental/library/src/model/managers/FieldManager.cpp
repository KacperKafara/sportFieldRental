//
// Created by student on 06.06.2022.
//

#include "model/managers/FieldManager.h"
#include "model/repositories/FieldRepository.h"
#include "model/Field.h"

void FieldManager::add(fieldPtr field){
    fieldRepository->add(field);
};

void FieldManager::remove(int id){
    fieldRepository->remove(id);
}

fieldPtr FieldManager::getFieldById(int id){
    return fieldRepository->get(id);
}

FieldManager::FieldManager(const fieldRepositoryPtr &fieldRepository) : fieldRepository(fieldRepository) {}
