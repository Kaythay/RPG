#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <string>
#include <QWidget>
#include "global.h"
#include "screen.h"

namespace Ui {
class StartScreen;
}

class StartScreen : public Screen
{
    Q_OBJECT

public:
    explicit StartScreen();
    ~StartScreen();

private:
    Ui::StartScreen *ui;

private slots:
    void nextScreen();
};

#endif // STARTSCREEN_H
