//
// Created by student on 04.06.2022.
//

#include "model/repositories/RentRepository.h"
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Field.h"

void RentRepository::add(rentPtr rent) {
    for(auto r : rents) {
        if(r->getId() == rent->getId()) {
            return;
        }
    }
    rents.push_back(rent);
}

void RentRepository::makeArchive(int id, datePtr time) {
    for(int i = 0; i < rents.size(); i++) {
        if(rents[i]->getId() == id) {
            rents[i]->endRent(time);
            archiveRents.push_back(rents[i]);
            rents.erase(rents.begin() + i);
        }
    }
}

rentPtr RentRepository::get(int id) {
    for(auto r : rents) {
        if(r->getField()->getId() == id) {
            return r;
        }
    }
    for(auto r : archiveRents) {
        if(r->getField()->getId() == id) {
            return r;
        }
    }
}

vector<rentPtr> RentRepository::get(string city, string street, string number) {
    vector<rentPtr> vec;
    for(auto r : rents) {
        addressPtr adr = r->getClient()->getAddress();
        if(adr->getCity() == city && adr->getStreet() == street && adr->getNumber() == number) vec.push_back(r);
    }
    for(auto r : archiveRents) {
        addressPtr adr = r->getClient()->getAddress();
        if(adr->getCity() == city && adr->getStreet() == street && adr->getNumber() == number) vec.push_back(r);
    }
    return vec;
}

const vector<rentPtr> &RentRepository::getRents() const {
    return rents;
}

const vector<rentPtr> &RentRepository::getArchiveRents() const {
    return archiveRents;
}

RentRepository::RentRepository() {}
