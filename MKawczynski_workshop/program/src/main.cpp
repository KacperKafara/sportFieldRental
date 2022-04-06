#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"

using namespace std;

int main()
{
    Address address("Lodz","al.Politechniki","1");
    Client client("Jan","Kowalski","1",&address);

    Vehicle vehicle("1",10);

    Rent rent1(1,&client,&vehicle);
    Rent rent2(2,&client,&vehicle);

    cout<<"rent"<<endl;
    cout<<rent1.getRentInfo()<<endl;
    cout<<"info"<<endl;
    cout<<client.getClientInfo()<<endl;
    cout<<"fullInfo"<<endl;
    cout<<client.getFullClientInfo();

    return 0;
}