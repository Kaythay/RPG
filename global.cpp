#include <iostream>
#include <string>
#include <QObject>
#include <QWidget>
#include <QString>
#include "global.h"
#include "player.h"
#include "unit.h"
#include "speechbox.h"
#include "speechboxlabel.h"

/** NOTE: This is the class used to contain objects and other variables that should be accessible to all classes in the game */


Global::Global(QObject *parent) : QObject(parent)
{
    this->mainW = new QWidget();
    this->mainW->resize(600,450);
    this->mainW->show();
}
