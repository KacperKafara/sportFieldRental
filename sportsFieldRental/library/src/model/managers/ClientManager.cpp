//
// Created by student on 06.06.2022.
//

#include "model/managers/ClientManager.h"
#include "model/repositories/ClientRepository.h"
#include "model/Client.h"

void ClientManager::add(clientPtr client){
    clientRepository->add(client);
};

void ClientManager::remove(string city, string street, string number){
    clientRepository->remove(city,street,number);
}

void ClientManager::changePhoneNumber(string phoneNumber, string city, string street, string number){
    clientRepository->get(city,street,number)->setPhoneNumber(phoneNumber);
}

ClientManager::ClientManager(const clientRepositoryPtr &clientRepository) : clientRepository(clientRepository) {}
