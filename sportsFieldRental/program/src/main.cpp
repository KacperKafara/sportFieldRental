#include <iostream>
#include "typedefs.h"
#include "model/managers/Manager.h"
#include "model/managers/ClientManager.h"
#include "model/repositories/ClientRepository.h"
#include "model/clientTypes/School.h"
#include "model/clientTypes/LeagueA.h"
#include "model/clientTypes/LeagueB.h"
#include "model/clientTypes/LeagueC.h"
#include "model/clientTypes/LeagueD.h"
#include "model/clientTypes/Club.h"
#include "model/managers/FieldManager.h"
#include "model/repositories/FieldRepository.h"
#include "model/repositories/RentRepository.h"
#include "model/managers/RentManager.h"
#include "model/Field.h"
#include "model/events/Training.h"
#include "model/events/Tournament.h"
#include "model/events/FriendlyMatch.h"
#include "model/Date.h"
#include "model/Client.h"
#include "model/Rent.h"

using namespace std;

datePtr getDate() {
    int year, month, day, hour, minute;
    cout << "Prosze podac rok: "; cin >> year;
    cout << "Prosze podac miesiac: "; cin >> month;
    cout << "Prosze podac dzien: "; cin >> day;
    cout << "Prosze podac godzine: "; cin >> hour;
    cout << "Prosze podac minute: "; cin >> minute;
    datePtr date = make_shared<Date>(year, month, day, hour, minute);
    return date;
}

void addClient(Manager *manager, string city, string street, string number) {
    int id = manager->getClientManager()->getClientRepository()->getClients().size() + 1;
    string phoneNumber, name;
    cout << "Prosze podac nazwe: "; cin.ignore( numeric_limits < streamsize >::max(), '\n' ); getline(cin, name);
    int type, league;
    cout << "Prosze podac numer telefonu: "; cin >> phoneNumber;
    cout << "Prosze podac typ(1-Szkola, 2-Klub): "; cin >> type;
    if(type == 2) {
        cout << "Prosze podac lige(1-Liga A, 2-Liga B, 3-Liga C, 4-Liga D): "; cin >> league;
        if(league == 1) {
            leaguePtr league1  = make_shared<LeagueA>();
            clientTypePtr type1 = make_shared<Club>(league1);
            manager->addClient(id, name, phoneNumber, city, street, number, type1);
        } else if(league == 2) {
            leaguePtr league1  = make_shared<LeagueB>();
            clientTypePtr type1 = make_shared<Club>(league1);
            manager->addClient(id, name, phoneNumber, city, street, number, type1);
        } else if(league == 3) {
            leaguePtr league1  = make_shared<LeagueC>();
            clientTypePtr type1 = make_shared<Club>(league1);
            manager->addClient(id, name, phoneNumber, city, street, number, type1);
        } else if(league == 4) {
            leaguePtr league1  = make_shared<LeagueD>();
            clientTypePtr type1 = make_shared<Club>(league1);
            manager->addClient(id, name, phoneNumber, city, street, number, type1);
        } else {
            cout << "Nie ma takiej opcji!" << endl;
            cout << "Nie udalo sie dodac klienta!" << endl;
        }
    } else if(type == 1) {
        clientTypePtr type1 = make_shared<School>();
        manager->addClient(id, name, phoneNumber, city, street, number, type1);
    } else {
        cout << "Nie ma takiej opcji!" << endl;
        cout << "Nie udalo sie dodac klienta" << endl;
    }
}

void registerClient(Manager *manager) {
    string city, street, number;
    cout << "Miasto: "; cin.ignore( numeric_limits < streamsize >::max(), '\n' ); getline(cin, city);
    cout << "Ulica: "; getline(cin, street);
    cout << "Numer domu: "; cin >> number;
    addClient(manager, city, street, number);
}

void addField(Manager *manager) {
    unsigned int id = manager->getFieldManager()->getFieldRepository()->getFields().size() + 1;
    int tribuneCapacity;
    double cost;
    string city, street, number;
    cout << "Prosze podac adres." << endl;
    cout << "Miasto: "; cin.ignore( numeric_limits < streamsize >::max(), '\n' ); getline(cin, city);
    cout << "Ulica: "; getline(cin, street);
    cout << "Numer domu: "; getline(cin, number);
    cout << "Pojemnosc trybun: "; cin >> tribuneCapacity;
    cout << "Koszt za godzine: "; cin >> cost;
    manager->addField(id, city, street, number, tribuneCapacity, cost);
}

void startRent(Manager *manager) {
    int id = manager->getRentManager()->getRentRepository()->getRents().size() +
             manager->getRentManager()->getRentRepository()->getArchiveRents().size() + 1;
    int fieldId, eventId;
    string city, street, number;
    cout << "Prosze podac swoj adres." << endl;
    cout << "Miasto: "; cin.ignore( numeric_limits < streamsize >::max(), '\n' ); getline(cin, city);
    cout << "Ulica: "; getline(cin, street);
    cout << "Numer domu: "; getline(cin, number);
    clientPtr cl = manager->getClientManager()->getClientByAddress(city, street, number);
    if(cl == nullptr) {
        addClient(manager, city, street, number);
        cl = manager->getClientManager()->getClientByAddress(city, street, number);
    }
    for(auto field : manager->getFieldManager()->getFieldRepository()->getFields()) {
        cout << field->getInfo() << endl;
    }
    cout << "Prosze wybrac boisko: "; cin >> fieldId;
    fieldPtr field = manager->getFieldById(fieldId);
    cout << "Prosze podac do czego zostanie wykorzystane boisko(1-Trening, 2-Turniej, 3-Mecz towarzyski): "; cin >> eventId;
    eventPtr ev;
    switch (eventId) {
        case 1:
            ev = make_shared<Training>();
            manager->startRent(id, ev, field, cl, getDate());
            break;
        case 2:
            ev = make_shared<Tournament>();
            manager->startRent(id, ev, field, cl, getDate());
            break;
        case 3:
            ev = make_shared<FriendlyMatch>();
            manager->startRent(id, ev, field, cl, getDate());
            break;
        default:
            cout << "Nie ma takiej opcji." << endl;
            break;
    }
    cout << "Id panskiego wyporzyczenia: " << id << endl;
}

void endRent(Manager *manager) {
    int id; datePtr date;
    cout << "Prosze podac id swojego wyporzyczenia: "; cin >> id;
    cout << "Prosze podac date zakonczenia wyporzyczenia: "; date = getDate();
    manager->endRent(id, date);
    cout << "Koszt wyporzycznia: " << manager->getRentManager()->getRentRepository()->get(id)->getRentCost() << endl;
}

void getInfoAboutClient(Manager *manager) {
    string city, street, number;
    cout << "Prosze podac miast: "; cin.ignore( numeric_limits < streamsize >::max(), '\n' ); getline(cin, city);
    cout << "Prosze podac ulice: "; getline(cin, street);
    cout << "Prosze podac numer domu: "; getline(cin, number);
    cout << manager->getClientByAddress(city, street, number)->getInfo() << endl;
}

void getInfoAboutField(Manager *manager) {
    int id;
    cout << "Podaj id boiska: "; cin >> id;
    cout << manager->getFieldById(id)->getInfo() << endl;
}

void getInfoAboutRentsForField(Manager *manager) {
    int id;
    cout << "Podaj id boiska: "; cin >> id;
    for(auto r : manager->getAllRentsForField(id)) {
        cout << r->getInfo() << endl;
    }
}

void getInfoAboutRentsForClient(Manager *manager) {
    string city, street, number;
    cout << "Prosze podac miast: "; cin.ignore( numeric_limits < streamsize >::max(), '\n' ); getline(cin, city);
    cout << "Prosze podac ulice: "; getline(cin, street);
    cout << "Prosze podac numer domu: "; getline(cin, number);
    for(auto r : manager->getAllRentsForClient(city, street, number)) {
        cout << r->getInfo() << endl;
    }
}

void changePhoneNumber(Manager *manager) {
    string city, street, number, newNumber;
    cout << "Prosze podac adres." << endl;
    cout << "Miasto: "; cin.ignore( numeric_limits < streamsize >::max(), '\n' ); getline(cin, city);
    cout << "Ulica: "; getline(cin, street);
    cout << "Numer: "; getline(cin, street);
    cout << "Prosze podac nowy numer telefonu: "; cin >> newNumber;
    manager->changeClientPhoneNumber(newNumber, city, street, number);
}

void menu() {
    cout << "----MENU----" << endl;
    cout << "1. Dodaj klienta" << endl;
    cout << "2. Dodaj orlik" << endl;
    cout << "3. Rozpocznij wypozyczenie" << endl;
    cout << "4. Zakoncz wyporzyczenie" << endl;
    cout << "5. Uzyskaj informacje o kliencie" << endl;
    cout << "6. Uzyskaj informacje o boisku" << endl;
    cout << "7. Zmien numer telefonu" << endl;
    cout << "8. Wyswietl informacje o wyporzyczeniach klienta" << endl;
    cout << "9. Wyswietl informacje o wyporzyczniach danego boiska" << endl;
    cout << "10. Zakoncz program" << endl;
    cout << "Co chcesz zrobic: ";
}

int main() {
    Manager *manager = new Manager;
    int running = 0;
    int choice;
    while(!running) {
        menu();
        cin >> choice;
        switch (choice) {
            case 1:
                registerClient(manager);
                break;
            case 2:
                addField(manager);
                break;
            case 3:
                startRent(manager);
                break;
            case 4:
                endRent(manager);
                break;
            case 5:
                getInfoAboutClient(manager);
                break;
            case 6:
                getInfoAboutField(manager);
                break;
            case 7:
                changePhoneNumber(manager);
                break;
            case 8:
                getInfoAboutRentsForClient(manager);
                break;
            case 9:
                getInfoAboutRentsForField(manager);
                break;
            default:
                running = 1;
                break;
        }
    }
    delete manager;
    return 0;
}