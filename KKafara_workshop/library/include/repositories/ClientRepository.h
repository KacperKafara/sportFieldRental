//
// Created by student on 11.04.2022.
//

#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H
#include "vector"
#include "typedefs.h"
#include <string>

using std::vector;
using std::string;

class ClientRepository {
private:
    vector<clientPtr> clientRepository;
public:
    const clientPtr get(int id) const;
    void add(clientPtr client);
    void remove(clientPtr client);
    const string report() const;
    const int size() const;
};

#endif //CARRENTAL_CLIENTREPOSITORY_H
