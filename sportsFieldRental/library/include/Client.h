//
// Created by student on 02.06.2022.
//

#ifndef SPORTSFIELDRENTAL_CLIENT_H
#define SPORTSFIELDRENTAL_CLIENT_H
#include <string>

using std::string;

class Client {
private:
    int id;
    string name;
    string phoneNumber;
public:
    Client(int id, const string &name, const string &phoneNumber);
    int getId() const;
    const string &getName() const;
    const string &getPhoneNumber() const;
};


#endif //SPORTSFIELDRENTAL_CLIENT_H
