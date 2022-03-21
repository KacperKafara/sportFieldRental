#ifndef OOPPROJECT_CLIENT_H
#define OOPPROJECT_CLIENT_H
#include <string>

using std::string;

class Client
{
private:
    string firstName;
    string lastName;
    string personaID;
public:
    Client();
    ~Client();
    string getClientInfo();
};

#endif //OOPPROJECT_CLIENT_H