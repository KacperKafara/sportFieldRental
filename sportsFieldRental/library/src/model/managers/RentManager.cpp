//
// Created by student on 06.06.2022.
//

#include "model/managers/RentManager.h"
#include "model/repositories/RentRepository.h"
#include "model/Rent.h"

RentManager::RentManager(const rentRepositoryPtr &rentRepository) {};

void RentManager::begin(int id, eventPtr event, fieldPtr field, clientPtr client, datePtr beginRentDate){
    rentPtr rent = make_shared<Rent>(id,event,client,field,beginRentDate);
    rentRepository->add(rent);
}
void RentManager::end(int id, datePtr endRentDate){
    rentRepository->get(id)->endRent(endRentDate);
}
vector<rentPtr> RentManager::getAllRentsForAddress(string city, string street, string number){
    return rentRepository->get(city,street,number);
}