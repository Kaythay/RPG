#include <string>
#include "item.h"

Item::Item(std::string n) {
    this->name = n;
}

/** Pass new name to rename item */
void Item::setName(std::string newName){
    this->name = newName;
    return;
}


/** Reduces the item's ammo by i. If no integer is passed, i is set to 1 as default */
void Item::reduceUses(int i){
    this->uses-= i;
    return;
}

std::string Item::getName(){return this->name;}

int Item::getAcc(){return this->acc;}

int Item::getPower(){return this->power;}
