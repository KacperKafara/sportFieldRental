//
// Created by student on 05.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/repositories/FieldRepository.h"
#include "model/Address.h"
#include "model/Field.h"

BOOST_AUTO_TEST_SUITE(FieldRepositorySuiteTest)

BOOST_AUTO_TEST_CASE(FieldRepositoryAddTest) {
    addressPtr address1 = make_shared<Address>("2", "3", "4");
    fieldPtr field = make_shared<Field>(1, 200, 300, address1);
    FieldRepository repo;
    BOOST_REQUIRE_EQUAL(repo.getFields().size(), 0);
    repo.add(field);
    BOOST_REQUIRE_EQUAL(repo.getFields().size(), 1);
    fieldPtr field1 = make_shared<Field>(1, 300, 400, address1);
    BOOST_REQUIRE_EQUAL(repo.getFields().size(), 1);
}

BOOST_AUTO_TEST_CASE(FieldRepositoryGetTest) {
    addressPtr address1 = make_shared<Address>("2", "3", "4");
    fieldPtr field = make_shared<Field>(1, 200, 300, address1);
    FieldRepository repo;
    BOOST_REQUIRE_EQUAL(repo.getFields().size(), 0);
    repo.add(field);
    BOOST_REQUIRE_EQUAL(repo.getFields().size(), 1);
    BOOST_REQUIRE_EQUAL(repo.get(1), field);
    }

BOOST_AUTO_TEST_SUITE_END()