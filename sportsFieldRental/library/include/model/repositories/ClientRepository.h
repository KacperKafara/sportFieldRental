//
// Created by student on 04.06.2022.
//

#ifndef SPORTSFIELDRENTAL_CLIENTREPOSITORY_H
#define SPORTSFIELDRENTAL_CLIENTREPOSITORY_H
#include <vector>
#include "typedefs.h"
#include <string>

using std::vector;
using std::string;

class ClientRepository {
private:
    vector<clientPtr> clients;
public:
    const vector<clientPtr> &getClients() const;
    void add(clientPtr client);
    clientPtr get(string city, string street, string number);
};


#endif //SPORTSFIELDRENTAL_CLIENTREPOSITORY_H
