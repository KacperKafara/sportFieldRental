//
// Created by student on 02.06.2022.
//

#ifndef SPORTSFIELDRENTAL_TYPEDEFS_H
#define SPORTSFIELDRENTAL_TYPEDEFS_H

#include <memory>

using std::shared_ptr;

class Address;
class Client;
class ClientType;
class League;

typedef shared_ptr<Address> addressPtr;
typedef shared_ptr<Client> clientPtr;
typedef shared_ptr<ClientType> clientTypePtr;
typedef shared_ptr<League> leaguePtr;

#endif //SPORTSFIELDRENTAL_TYPEDEFS_H
