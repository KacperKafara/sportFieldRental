//
// Created by student on 16.03.2022.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H
#include <string>

using std::string;

class Client {
private:
    string firstName;
    string lastName;
    string personalID;
public:
    Client(string fn, string ln, string id);
    ~Client();
    const string &getFirstName() const;
    const string &getLastName() const;
    const string &getPersonalId() const;
    void setFirstName(const string &firstName);
    void setLastName(const string &lastName);

    string getClientInfo();
};
#endif //CARRENTAL_CLIENT_H
