//
// Created by student on 06.06.2022.
//

#include "model/managers/RentManager.h"
#include "model/Field.h"
#include "model/repositories/RentRepository.h"
#include "model/Rent.h"

RentManager::RentManager() {
    rentRepository = make_shared<RentRepository>();
};

void RentManager::begin(int id, eventPtr event, fieldPtr field, clientPtr client, datePtr beginRentDate){
    rentPtr rent = make_shared<Rent>(id,event,client,field,beginRentDate);
    rentRepository->add(rent);
}

void RentManager::end(int id, datePtr endRentDate){
    rentRepository->makeArchive(id, endRentDate);
}

vector<rentPtr> RentManager::getAllRentsForClient(string city, string street, string number){
    return rentRepository->get(city,street,number);
}

const rentRepositoryPtr &RentManager::getRentRepository() const {
    return rentRepository;
}

vector<rentPtr> RentManager::getAllRentsForField(int fieldId) {
    vector<rentPtr> vec;
    for(auto r : rentRepository->getArchiveRents()){
        if(r->getField()->getId() == fieldId) vec.push_back(r);
    }
    for(auto r : rentRepository->getRents()){
        if(r->getField()->getId() == fieldId) vec.push_back(r);
    }
    return vec;
}
