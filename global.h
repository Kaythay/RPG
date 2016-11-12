#ifndef COMMON_H
#define COMMON_H

#include "player.h"
#include "glass.h"

class Global {
public:
    explicit Global();
    static Player * player;
    static MainWindow * mainWin;
    static int i;

};

#endif // COMMON_H
