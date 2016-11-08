#include <QApplication>
#include <QWidget>
#include <QFont>
#include <QMouseEvent>
#include "unit.h"
#include "startscreen.h"
#include "playercreatescreen.h"
#include "global.h"

using namespace std;

Global * global;

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    QApplication::setFont(QFont("Fixedsys"));

    global = new Global();


    //set up start Screen
    StartScreen * start = new StartScreen(*global);
    start->show();

    return app.exec();
}
