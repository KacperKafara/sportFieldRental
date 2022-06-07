//
// Created by student on 06.06.2022.
//

#ifndef SPORTSFIELDRENTAL_MANAGER_H
#define SPORTSFIELDRENTAL_MANAGER_H
#include "typedefs.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Manager {
private:
    clientManagerPtr clientManager;
    fieldManagerPtr fieldManager;
    rentManagerPtr rentManager;
public:
    Manager();
    void addClient(int id, string name, string phoneNumber, string city, string street, string number, clientTypePtr clientType);
    void changeClientPhoneNumber(string phoneNumber, string city, string street, string number);
    void startRent(int id, eventPtr event, fieldPtr field, clientPtr client, datePtr beginRentDate);
    void endRent(int id, datePtr endRentDate);
    vector<rentPtr> getAllRentsForField(int fieldId);
    vector<rentPtr> getAllRentsForClient(string city, string street, string number);
    void addField(int id, string city, string street, string number, int tribuneCapacity, double cost);
    fieldPtr getFieldById(int id);
    clientPtr getClientByAddress(string city, string street, string number);
    const clientManagerPtr &getClientManager() const;
    const fieldManagerPtr &getFieldManager() const;
    const rentManagerPtr &getRentManager() const;
    ~Manager();
};


#endif //SPORTSFIELDRENTAL_MANAGER_H
