#ifndef PLAYERCREATESCREEN_H
#define PLAYERCREATESCREEN_H

#include <string>
#include "global.h"
#include "screen.h"
#include "unit.h"
#include "player.h"


namespace Ui {
class PlayerCreateScreen;
}

class PlayerCreateScreen : public Screen
{
    Q_OBJECT

public:
    explicit PlayerCreateScreen();
    ~PlayerCreateScreen();

    //validation functions
    bool isNameValid();
    bool isGenderValid();

private:
    Ui::PlayerCreateScreen *ui;

    std::string n;               /* string used to hold the name inputted by player */
    UnitConstants::gender gen;     /* enum used to hold the gender selected by player */

private slots:
    void done(); /* slot used to detect when player is is finished creating unit */
};

#endif // PLAYERCREATESCREEN_H
