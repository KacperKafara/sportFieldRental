//
// Created by student on 06.06.2022.
//

#ifndef SPORTSFIELDRENTAL_CLIENTMANAGER_H
#define SPORTSFIELDRENTAL_CLIENTMANAGER_H

#include "typedefs.h"
#include <string>

using std::string;

class ClientManager{
private:
    clientRepositoryPtr clientRepository;
public:
    ClientManager(const clientRepositoryPtr &clientRepository);

    void add(clientPtr client);
    void remove(string city, string street, string number);
    void changePhoneNumber(string phoneNumber, string city, string street, string number);
};

#endif //SPORTSFIELDRENTAL_CLIENTMANAGER_H
