#include <iostream>
#include "model/Rent.h"
#include "model/events/Training.h"
#include "model/events/Tournament.h"
#include "model/clientTypes/School.h"
#include "model/clientTypes/LeagueA.h"
#include "model/clientTypes/Club.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Field.h"
#include "model/Date.h"

using namespace std;

int main() {
    eventPtr event = make_shared<Tournament>();
    leaguePtr league = make_shared<LeagueA>();
    clientTypePtr clientType = make_shared<Club>(league);
    addressPtr address = make_shared<Address>("1", "2", "3");
    clientPtr client = make_shared<Client>(1, "123", "1234", address, clientType);

    addressPtr address1 = make_shared<Address>("2", "3", "4");
    fieldPtr field = make_shared<Field>(1, 200, 300, address1);
    datePtr date1 = make_shared<Date>(1,1,1,12,1);
    datePtr date2 = make_shared<Date>(1,1,1,14,1);
    rentPtr rent = make_shared<Rent>(1, event, client, field,date1);

    rent->endRent(date2);
    cout << clientType->getDiscount();
    return 0;
}