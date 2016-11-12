#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "unit.h"

class Player : public Unit
{
public:
    Player(std::string n, unit_constants::gender g);
};

#endif // PLAYER_H
