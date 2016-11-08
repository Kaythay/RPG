#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>
#include "item.h"

namespace UnitConstants{
    enum gender{
        MALE,
        FEMALE
    };
}

class Unit {
public:
    explicit Unit(std::string n, int HP, int r, int at, int df, int ch, UnitConstants::gender g);
    void fight(Item &wpn, Unit &foe);
    void reduceHp(int i);

    //all getter methods
    std::string getName();
    int getTotalHp();
    int getCurrentHp();
    int getAttack();
    int getDefense();
    int getChance();

protected:
    std::string name;
    UnitConstants::gender gender;
    int HP, walkRange, attack, defense, chance, totalHp, currentHp;

    int calculateChance(Item wpn, Unit foe);
};

#endif // UNIT_H
