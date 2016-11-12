#include <QApplication>
#include <QWidget>
#include <QFont>
#include <QMouseEvent>
#include "startscreen.h"

using namespace std;

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    QApplication::setFont(QFont("Fixedsys"));


    Global::mainWin = new MainWindow();

    //set up start Screen
    StartScreen * start = new StartScreen();
    start->show();

    return app.exec();
}
