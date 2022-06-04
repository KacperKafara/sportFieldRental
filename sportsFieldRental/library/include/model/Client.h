//
// Created by student on 02.06.2022.
//

#ifndef SPORTSFIELDRENTAL_CLIENT_H
#define SPORTSFIELDRENTAL_CLIENT_H
#include <string>
#include "typedefs.h"
#include "Address.h"

using std::string;

class Client {
private:
    int id;
    string name;
    string phoneNumber;
    addressPtr address;
    clientTypePtr clientType;
public:
    Client(int id, const string &name, const string &phoneNumber, const addressPtr &address,
           const clientTypePtr &clientType);
    int getId() const;
    const string &getName() const;
    const string &getPhoneNumber() const;
    const addressPtr &getAddress() const;

    const clientTypePtr &getClientType() const;

    const string &getType() const;
};


#endif //SPORTSFIELDRENTAL_CLIENT_H
