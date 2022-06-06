//
// Created by student on 02.06.2022.
//

#ifndef SPORTSFIELDRENTAL_TYPEDEFS_H
#define SPORTSFIELDRENTAL_TYPEDEFS_H

#include <memory>

using std::shared_ptr;
using std::make_shared;

class Address;
class Client;
class ClientType;
class League;
class Event;
class Field;
class Rent;
struct Date;
class ClientRepository;
class RentRepository;
class FieldRepository;
class ClientManager;
class FieldManager;
class RentManager;

typedef shared_ptr<Address> addressPtr;
typedef shared_ptr<Client> clientPtr;
typedef shared_ptr<ClientType> clientTypePtr;
typedef shared_ptr<League> leaguePtr;
typedef shared_ptr<Event> eventPtr;
typedef shared_ptr<Field> fieldPtr;
typedef shared_ptr<Rent> rentPtr;
typedef shared_ptr<Date> datePtr;
typedef shared_ptr<ClientRepository> clientRepositoryPtr;
typedef shared_ptr<RentRepository> rentRepositoryPtr;
typedef shared_ptr<FieldRepository> fieldRepositoryPtr;
typedef shared_ptr<ClientManager> clientManagerPtr;
typedef shared_ptr<FieldManager> fieldManagerPtr;
typedef shared_ptr<RentManager> rentManagerPtr;

#endif //SPORTSFIELDRENTAL_TYPEDEFS_H
