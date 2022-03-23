#ifndef OOPPROJECT_CLIENT_H
#define OOPPROJECT_CLIENT_H
#include <string>

using namespace std;

class Client
{
private:
    string firstName;
    string lastName;
    string personalID;
public:
    Client();

    Client(string firstName, string lastName, string personalID);

    ~Client();
    string getClientInfo();
};

#endif OOPPROJECT_CLIENT_H