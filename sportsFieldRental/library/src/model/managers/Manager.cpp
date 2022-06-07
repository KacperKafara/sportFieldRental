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
#include "model/events/Tournament.h"
#include "model/events/Training.h"
#include "model/events/FriendlyMatch.h"

using std::ofstream;
using std::ifstream;
using std::getline;

void Manager::changeClientPhoneNumber(string phoneNumber, string city, string street, string number) {
    clientManager->changePhoneNumber(phoneNumber, city, street, number);
}

void Manager::addClient(int id, string name, string phoneNumber, string city, string street, string number, clientTypePtr clientType) {
    addressPtr address = make_shared<Address>(city, street, number);
    clientPtr client = make_shared<Client>(id, name, phoneNumber, address, clientType);
    clientManager->add(client);
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

    clientManager->getClientRepository()->getClients().clear();
    fieldManager->getFieldRepository()->getFields().clear();
    clientManager->getClientRepository()->getClients().clear();

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
            } else if(line == "" && counter != 0) {
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
    bool isArchive = 0;
    string event;
    int fieldId;
    int day, month, year, hour, minute;
    int eday, emonth, eyear, ehour, eminute;
    string tmp, tmp1;
    eventPtr eventt;
    clientPtr cl;
    fieldPtr fi;
    datePtr da, eda;
    if(rentFile.good()){
        while(rentFile) {
            getline(rentFile, line);
            if(line != "") {
                if (counter == 0) {
                    if (line == "1") isArchive = 1;
                } else if (counter == 1) {
                    id = std::stoi(line);
                } else if (counter == 2) {
                    event = line;
                } else if (counter == 3) {
                    fieldId = std::stoi(line);
                } else if (counter == 4) {
                    city = line;
                } else if (counter == 5) {
                    street = line;
                } else if (counter == 6) {
                    number = line;
                } else if (counter == 7 && isArchive == 0) {
                    day = std::stoi(line);
                } else if (counter == 8 && isArchive == 0) {
                    month = std::stoi(line);
                } else if (counter == 9 && isArchive == 0) {
                    year = std::stoi(line);
                } else if (counter == 10 && isArchive == 0) {
                    hour = std::stoi(line);
                } else if (counter == 11 && isArchive == 0) {
                    minute = std::stoi(line);
                } else if (counter == 7 && isArchive == 1) {
                    day = std::stoi(line.substr(0, line.find(" ")));
                    eday = std::stoi(line.substr(line.find(" ") + 1, line.size() - 1));
                } else if (counter == 8 && isArchive == 1) {
                    month = std::stoi(line.substr(0, line.find(" ")));
                    emonth = std::stoi(line.substr(line.find(" ") + 1, line.size() - 1));
                } else if (counter == 9 && isArchive == 1) {
                    year = std::stoi(line.substr(0, line.find(" ")));
                    eyear = std::stoi(line.substr(line.find(" ") + 1, line.size() - 1));
                } else if (counter == 10 && isArchive == 1) {
                    hour = std::stoi(line.substr(0, line.find(" ")));
                    ehour = std::stoi(line.substr(line.find(" ") + 1, line.size() - 1));
                } else if (counter == 11 && isArchive == 1) {
                    minute = std::stoi(line.substr(0, line.find(" ")));
                    eminute = std::stoi(line.substr(line.find(" ") + 1, line.size() - 1));
                }
                counter++;
            } else if(isArchive == 0 && line == "" && counter != 0) {
                if(event == "Training") {
                    eventt = make_shared<Training>();
                } else if(event == "Friendly Match") {
                    eventt = make_shared<FriendlyMatch>();
                } else if(event == "Tournament") {
                    eventt = make_shared<Tournament>();
                }
                cl = this->getClientByAddress(city, street, number);
                fi = this->getFieldById(fieldId);
                da = make_shared<Date>(year, month, day, hour, minute);
                this->startRent(id, eventt, fi, cl, da);
                counter = 0;
            } else if(isArchive == 1 && line == "" && counter != 0) {
                if(event == "Training") {
                    eventt = make_shared<Training>();
                } else if(event == "Friendly Match") {
                    eventt = make_shared<FriendlyMatch>();
                } else if(event == "Tournament") {
                    eventt = make_shared<Tournament>();
                }
                cl = this->getClientByAddress(city, street, number);
                fi = this->getFieldById(fieldId);
                da = make_shared<Date>(year, month, day, hour, minute);
                eda = make_shared<Date>(eyear, emonth, eday, ehour, eminute);
                this->startRent(id, eventt, fi, cl, da);
                this->endRent(id, eda);
                counter = 0;
            }
        }
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
                 << rent->getBeginRentDate()->day <<"\n"
                 << rent->getBeginRentDate()->month << "\n"
                 << rent->getBeginRentDate()->year << "\n"
                 << rent->getBeginRentDate()->hour << "\n"
                 << rent->getBeginRentDate()->minute << "\n\n";
    }
    vector<rentPtr> rtmp1 = rentManager->getRentRepository()->getArchiveRents();
    for(auto rent : rtmp1) {
        adr = rent->getClient()->getAddress();
        rentFile << rent->isArchive() << "\n"
                 << rent->getId() << "\n"
                 << rent->getEvent() << "\n"
                 << rent->getField()->getId() << "\n"
                 << adr->getCity() << "\n"
                 << adr->getStreet() << "\n"
                 << adr->getNumber() << "\n"
                << rent->getBeginRentDate()->day << " " <<rent->getEndRentDate()->day << "\n"
                << rent->getBeginRentDate()->month << " " <<rent->getEndRentDate()->month << "\n"
                << rent->getBeginRentDate()->year << " " <<rent->getEndRentDate()->year << "\n"
                << rent->getBeginRentDate()->hour << " " <<rent->getEndRentDate()->hour << "\n"
                << rent->getBeginRentDate()->minute << " " <<rent->getEndRentDate()->minute << "\n\n";
    }
    rentFile.close();
}
