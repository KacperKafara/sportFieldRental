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

using namespace std;

void registerClient(Manager *manager) {
    int id = manager->getClientManager()->getClientRepository()->getClients().size() + 1, type, league;
    string name, phoneNumber, city, street, number;
    cout << "Prosze podac nazwe: "; cin.ignore( numeric_limits < streamsize >::max(), '\n' ); getline(cin, name);
    cout << "Prosze podac adres." << endl;
    cout << "Miasto: "; getline(cin, city);
    cout << "Ulica: "; getline(cin, street);
    cout << "Numer domu: "; cin >> number;
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
        clientTypePtr type = make_shared<School>();
        manager->addClient(id, name, phoneNumber, city, street, number, type);
    } else {
        cout << "Nie ma takiej opcji!" << endl;
        cout << "Nie udalo sie dodac klienta" << endl;
    }
}

void addField(Manager *manager) {
    int id = manager->getFieldManager()->getFieldRepository()->getFields().size() + 1;
    int tribuneCapacity;
    double cost;
    string city, street, number;
    cout << "Prosze podac adres." << endl;
    cout << "Miasto: "; cin.ignore( numeric_limits < streamsize >::max(), '\n' ); getline(cin, city);
    cout << "Ulica: "; getline(cin, street);
    cout << "Numer: "; getline(cin, number);
    cout << "Pojemnosc trybun: "; cin >> tribuneCapacity;
    cout << "Koszt za godzine: "; cin >> cost;
    manager->addField(id, city, street, number, tribuneCapacity, cost);
}

void menu() {
    cout << "----MENU----" << endl;
    cout << "1. Dodaj klienta" << endl;
    cout << "2. Dodaj orlik" << endl;
    cout << "3. Rozpocznij wypozyczenie" << endl;
    cout << "4. Zakoncz wyporzyczenie" << endl;
    cout << "5. Uzyskaj informacje o kliencie" << endl;
    cout << "6. Uzyskaj informacje o boisku" << endl;
    cout << "7. Uzyskaj informacje o wyporzyczeniu" << endl;
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
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                running = 1;
                break;
        }
    }
    delete manager;
    return 0;
}