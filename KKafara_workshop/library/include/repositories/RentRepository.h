//
// Created by student on 11.04.2022.
//

#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H
#include "vector"
#include "typedefs.h"
#include <string>

using std::vector;
using std::string;

class Rent;

class RentRepository {
private:
    vector<rentPtr> rentRepository;
public:
    const rentPtr get(int id) const;
    void add(rentPtr rent);
    void remove(rentPtr rent);
    const string report() const;
    const int size() const;
    vector<rentPtr> findBy(RentPredicate predicate) const;
    vector<rentPtr> findAll() const;

};


#endif //CARRENTAL_RENTREPOSITORY_H
