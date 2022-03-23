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
    Client();
public:
    Client(string firstName, string lastName, string personalID);

    ~Client();
    string getClientInfo();

    string getFirstName();

    void setFirstName(string firstName);

    string getLastName();

    void setLastName(string lastName);

    string getPersonalID();

    void setPersonalID(string personalID);
};

#endif OOPPROJECT_CLIENT_H