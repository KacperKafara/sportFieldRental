//
// Created by student on 11.04.2022.
//

#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H
#include "vector"
#include "typedefs.h"
#include <string>

using std::vector;
using std::string;

class VehicleRepository {
private:
    vector<vehiclePtr> vehicleRepository;
public:
    const vehiclePtr get(int id) const;
    void add(vehiclePtr vehicle);
    void remove(vehiclePtr vehicle);
    const string report() const;
    const int size() const;
    vector<vehiclePtr> findBy(VehiclePredicate predicate) const;
    vector<vehiclePtr> findAll() const;
    vehiclePtr findByPlateNumber(string plateNumber);
};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
