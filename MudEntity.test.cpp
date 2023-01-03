# define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "MudEntity.hpp"

TEST_CASE("MudEntity::setName() and MudEntity::getName() both set and get correctly") {
    MudEntity tEntity;
    string name = "FAKE NAME";
    
    tEntity.setName(name);
    
    CHECK(tEntity.getName() == name);
}

TEST_CASE("MudEntity::setDescription() and MudEntity::getDescription() both set and get correctly.") {
    MudEntity tEntity;
    string description = "FAKE DESCRIPTION";
    
    tEntity.setDescription(description);
    
    CHECK(tEntity.getDescription() == description);
}

TEST_CASE("MudEntity::addKeyword() and MudEntity::isKeyword() will add and check keywords correctly") {
    MudEntity tEntity;
    string kw1 = "TEST";
    string kw2 = "mob";
    string kw3 = "Test";
    string kw4 = "test";
    
    tEntity.addKeyword(kw1);
    tEntity.addKeyword(kw3);
    
    CHECK(tEntity.isKeyword(kw1) == true);
    CHECK(tEntity.isKeyword(kw2) == false);
    CHECK(tEntity.isKeyword(kw3) == true);
    CHECK(tEntity.isKeyword(kw4) == false);
}
