//
// Created by student on 11.04.2022.
//

#include "repositories/RentRepository.h"

const rentPtr RentRepository::get(int id) const {
    if(id >= 0 && size() > id)
        return rentRepository[id];
    return nullptr;
}

void RentRepository::add(rentPtr rent) {
    if(rent)
        rentRepository.push_back(rent);
}

void RentRepository::remove(rentPtr rent) {
    if(rent)
        rentRepository.erase(std::remove(rentRepository.begin(), rentRepository.end(), rent), rentRepository.end());
}

const string RentRepository::report() const {
    string info = "";
    for(int i = 0; i < rentRepository.size(); i++) {
        info = info + rentRepository[i]->getRentInfo() + "\n";
    }
    return info;
}

const int RentRepository::size() const {
    return rentRepository.size();
}

vector<rentPtr> RentRepository::findBy(RentPredicate predicate) const {
    vector<rentPtr> found;
    for (unsigned int i = 0; i < rentRepository.size(); i++) {
        rentPtr rent = get(i);
        if (rent != nullptr && predicate(rent)) {
            found.push_back(rent);
        }
    }
    return found;
}

bool returnTrue(rentPtr rent) {
    return true;
}

vector<rentPtr> RentRepository::findAll() const {
    return findBy(returnTrue);
}