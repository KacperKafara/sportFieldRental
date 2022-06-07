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
    ClientManager();
    void add(clientPtr client);
    void changePhoneNumber(string phoneNumber, string city, string street, string number);
    clientPtr getClientByAddress(string city, string street, string number);
    const clientRepositoryPtr &getClientRepository() const;
};

#endif //SPORTSFIELDRENTAL_CLIENTMANAGER_H
