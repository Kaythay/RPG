#ifndef FORESTSCREEN_H
#define FORESTSCREEN_H

#include <string>
#include <QWidget>
#include "global.h"
#include "screen.h"

namespace Ui {
class ForestScreen;
}

class ForestScreen : public Screen
{
    Q_OBJECT

public:
    explicit ForestScreen();
    ~ForestScreen();

private:
    Ui::ForestScreen *ui;
};

#endif // FORESTSCREEN_H
