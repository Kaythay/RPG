#include <iostream>
#include <string>
#include "unit.h"
#include "item.h"

Unit::Unit(std::string n, int HP, int r, int df, int at, int ch, UnitConstants::gender g){
    this->name = n;
    this->HP = this->totalHp = this->currentHp = HP;
    this->walkRange = r;
    this->attack = at;
    this->defense = df;
    this->chance = ch;
    this->gender = g;
}


/* this unit attacks the foe unit using wpn */
void Unit::fight(Item &wpn, Unit &foe){

    int dmg = (this->attack - foe.getAttack()) * wpn.getPower();
    int chance = this->calculateChance(wpn, foe);

    //TODO: get a true random number between 0 and 100 (currently only pseudo random)
    int r = rand() % 100;

    if (r <= chance){
        //attack was successful
        foe.reduceHp(dmg);
        wpn.reduceUses();
    }

    return;
}

/* calculates chance of an attacking being succesful */
int Unit::calculateChance(Item wpn, Unit foe){
    return
    (
        (
            ( this->chance - foe.getChance() )
            * wpn.getAcc()
            * 50
        )
        /this->chance
    );
}

void Unit::reduceHp(int i){ this->currentHp -= i; return; }
std::string Unit::getName(){return this->name;}
int Unit::getTotalHp()     {return this->totalHp;}
int Unit::getCurrentHp()   {return this->currentHp;}
int Unit::getAttack()        {return this->attack;}
int Unit::getDefense()        {return this->defense;}
int Unit::getChance()       {return this->chance;}
