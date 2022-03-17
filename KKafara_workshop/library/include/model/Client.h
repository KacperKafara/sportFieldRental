//
// Created by student on 16.03.2022.
//

#ifndef OOPPROJECT_CLIENT_H
#define OOPPROJECT_CLIENT_H
#include <string>

using std::string;

class Client {
private:
    string firstName;
    string lastName;
    string personalID;
public:
//    Client();
    Client(string fn, string ln, string id);
    ~Client();
    string getClientInfo();
};


#endif OOPPROJECT_CLIENT_H
