#include <iostream>
#include <string>
#include "player.h"
#include "unit.h"

Player::Player(std::string n, unit_constants::gender g) : Unit(n, 20, 5, 5, 5, 5, g) {

}
