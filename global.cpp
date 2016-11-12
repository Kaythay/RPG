#include <iostream>
#include <string>
#include "global.h"
#include "player.h"
#include "glass.h"

/** NOTE: This is the class used to contain objects
 * and other variables that should be accessible to all classes in the game */

int Global::i = 0;
MainWindow* Global::mainWin = NULL;
Player* Global::player = NULL;

Global::Global() {
}
