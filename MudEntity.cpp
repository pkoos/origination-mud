#include "MudEntity.hpp"

string MudEntity::getName() {
    return _name;
}

void MudEntity::setName(string name) {
    _name = name;
}

string MudEntity::getDescription() {
    return _description;
}

void MudEntity::setDescription(string description) {
    _description = description;
}

void MudEntity::addKeyword(string word) {
    _keywords.push_back(word);
}

bool MudEntity::isKeyword(string word) {
    for(string keyword : _keywords) {
        if (word == keyword)
            return true;
    }
    return false;
}