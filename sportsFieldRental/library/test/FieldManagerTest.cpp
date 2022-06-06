//
// Created by student on 05.06.2022.
//

#include <boost/test/unit_test.hpp>
#include "model/repositories/FieldRepository.h"
#include "model/Address.h"
#include "model/Field.h"
#include "model/managers/FieldManager.h"

BOOST_AUTO_TEST_SUITE(FieldManagerSuiteTest)

BOOST_AUTO_TEST_CASE(FieldManagerAddAndRemoveTest) {
    addressPtr address = make_shared<Address>("1", "2", "3");
    fieldPtr field = make_shared<Field>(1, 1, 1, address);
    fieldRepositoryPtr repo = make_shared<FieldRepository>();
    FieldManager fieldManager(repo);

    fieldManager.add(field);
    BOOST_REQUIRE_EQUAL(repo->getFields().size(), 1);
    fieldManager.remove(1);
    BOOST_REQUIRE_EQUAL(repo->getFields().size(), 0);
}

BOOST_AUTO_TEST_CASE(FieldManagerGetTest) {
    addressPtr address = make_shared<Address>("1", "2", "3");
    fieldPtr field = make_shared<Field>(1, 1, 1, address);
    fieldRepositoryPtr repo = make_shared<FieldRepository>();
    FieldManager fieldManager(repo);

    fieldManager.add(field);

    BOOST_REQUIRE_EQUAL(repo->get(1), field);
}


BOOST_AUTO_TEST_SUITE_END()