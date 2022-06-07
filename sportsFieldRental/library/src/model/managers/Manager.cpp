//
// Created by student on 06.06.2022.
//

#include <iostream>
#include "model/managers/Manager.h"
#include "model/managers/ClientManager.h"
#include "model/managers/FieldManager.h"
#include "model/managers/RentManager.h"
#include "model/Client.h"
#include "model/Rent.h"
#include "model/Field.h"
#include "model/Address.h"
#include "model/repositories/ClientRepository.h"
#include <fstream>
#include "model/repositories/FieldRepository.h"
#include "model/repositories/RentRepository.h"
#include "model/Date.h"
#include "model/clientTypes/School.h"
#include "model/clientTypes/LeagueA.h"
#include "model/clientTypes/LeagueB.h"
#include "model/clientTypes/LeagueC.h"
#include "model/clientTypes/LeagueD.h"
#include "model/clientTypes/Club.h"

using std::ofstream;
using std::ifstream;
using std::getline;

void Manager::addClient(int id, string name, string phoneNumber, string city, string street, string number, clientTypePtr clientType) {
    addressPtr address = make_shared<Address>(city, street, number);
    clientPtr client = make_shared<Client>(id, name, phoneNumber, address, clientType);
    clientManager->add(client);
}

void Manager::changeClientPhoneNumber(string phoneNumber, string city, string street, string number) {
    clientManager->changePhoneNumber(phoneNumber, city, street, number);
}

void Manager::startRent(int id, eventPtr event, fieldPtr field, clientPtr client, datePtr beginRentDate) {
    rentManager->begin(id, event, field, client, beginRentDate);
}

void Manager::endRent(int id, datePtr endRentDate) {
    rentManager->end(id, endRentDate);
}

vector<rentPtr> Manager::getAllRentsForField(int fieldId) {
    return rentManager->getAllRentsForField(fieldId);
}

vector<rentPtr> Manager::getAllRentsForClient(string city, string street, string number) {
    return rentManager->getAllRentsForClient(city, street, number);
}

void Manager::addField(int id, string city, string street, string number, int tribuneCapacity, double cost) {
    addressPtr address = make_shared<Address>(city, street, number);
    fieldPtr field = make_shared<Field>(id, tribuneCapacity, cost, address);
    fieldManager->add(field);
}

fieldPtr Manager::getFieldById(int id) {
    return fieldManager->getFieldById(id);
}

clientPtr Manager::getClientByAddress(string city, string street, string number) {
    return clientManager->getClientByAddress(city, street, number);
}

const clientManagerPtr &Manager::getClientManager() const {
    return clientManager;
}

const fieldManagerPtr &Manager::getFieldManager() const {
    return fieldManager;
}

const rentManagerPtr &Manager::getRentManager() const {
    return rentManager;
}

Manager::Manager() {
    clientManager = make_shared<ClientManager>();
    fieldManager = make_shared<FieldManager>();
    rentManager = make_shared<RentManager>();

    ifstream fieldFile("fields.txt");
    string line;
    int counter = 0;
    int id, tribune, cost;
    string city, street, number;
    if(fieldFile.good()) {
        while(fieldFile) {
            getline(fieldFile, line);
            if(line != ""){
                if(counter == 0)
                    id = std::stoi(line);
                else if(counter == 1)
                    tribune = std::stoi(line);
                else if(counter == 2)
                    cost = std::stoi(line);
                else if(counter == 3)
                    city = line;
                else if(counter == 4)
                    street = line;
                else if(counter == 5)
                    number = line;
                counter++;
            } else {
                counter = 0;
                this->addField(id, city, street, number, tribune, cost);
            }
        }
    }
    fieldFile.close();

    ifstream clientFile("clients.txt");
    counter = 0;
    string name, phoneNumber;
    clientTypePtr ctype;
    leaguePtr league;
    line = "";
    if(clientFile.good()) {
        while(clientFile) {
            getline(clientFile, line);
            if(line != "") {
                if(counter == 0)
                    id = std::stoi(line);
                else if(counter == 1)
                    name = line;
                else if(counter == 2)
                    phoneNumber = line;
                else if(counter == 3)
                    city = line;
                else if(counter == 4)
                    street = line;
                else if(counter == 5)
                    number = line;
                else if(counter == 6) {
                    if (line == "School") {
                        ctype = make_shared<School>();
                    } else {
                        if(line[line.size() - 1] == 'A') {
                            league = make_shared<LeagueA>();
                            ctype = make_shared<Club>(league);
                        } else if(line[line.size() - 1] == 'B') {
                            league = make_shared<LeagueB>();
                            ctype = make_shared<Club>(league);
                        } else if(line[line.size() - 1] == 'C') {
                            league = make_shared<LeagueC>();
                            ctype = make_shared<Club>(league);
                        } else if(line[line.size() - 1] == 'D') {
                            league = make_shared<LeagueD>();
                            ctype = make_shared<Club>(league);
                        }
                    }
                }
                counter++;
            } else if(line == "" && counter != 0) {
                counter = 0;
                this->addClient(id, name, phoneNumber, city, street, number, ctype);
            }
        }
    }
    clientFile.close();

    ifstream rentFile("rents.txt");
    counter = 0;
    if(rentFile.good()){

    }
    rentFile.close();
}

Manager::~Manager() {
    ofstream fieldFile("fields.txt");
    vector<fieldPtr> tmp = fieldManager->getFieldRepository()->getFields();
    addressPtr adr;
    clientTypePtr type;
    for(auto field : tmp) {
        adr = field->getAddress();
        fieldFile << field->getId() << "\n"
                  << field->getTribuneCapacity() << "\n"
                  << field->getBaseCost() << "\n"
                  << adr->getCity() << "\n"
                  << adr->getStreet() << "\n"
                  << adr->getNumber() << "\n\n";
    }
    fieldFile.close();

    ofstream clientFile("clients.txt");
    vector<clientPtr> ctmp = clientManager->getClientRepository()->getClients();
    for(auto client : ctmp) {
        adr = client->getAddress();
        type = client->getClientType();
        if(type->getType() == "Club") {
            clientFile << client->getId() << "\n"
                       << client->getName() << "\n"
                       << client->getPhoneNumber() << "\n"
                       << adr->getCity() << "\n"
                       << adr->getStreet() << "\n"
                       << adr->getNumber() << "\n"
                       << type->getInfoForWriteToFile() << "\n\n";
        } else if(type->getType() == "School") {
            clientFile << client->getId() << "\n"
                       << client->getName() << "\n"
                       << client->getPhoneNumber() << "\n"
                       << adr->getCity() << "\n"
                       << adr->getStreet() << "\n"
                       << adr->getNumber() << "\n"
                       << type->getType() << "\n\n";
        }
    }
    clientFile.close();

    ofstream rentFile("rents.txt");
    vector<rentPtr> rtmp = rentManager->getRentRepository()->getRents();
    for(auto rent : rtmp) {
        adr = rent->getClient()->getAddress();
        rentFile << rent->isArchive() << "\n"
                 << rent->getId() << "\n"
                 << rent->getEvent() << "\n"
                 << rent->getField()->getId() << "\n"
                 << adr->getCity() << "\n"
                 << adr->getStreet() << "\n"
                 << adr->getNumber() << "\n"
                 << rent->getBeginRentDate()->getInfo() <<"\n\n";
    }
    rentFile.close();
}
