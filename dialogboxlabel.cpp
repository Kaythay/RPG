#include <iostream>
#include <string>
#include <QWidget>
#include <QObject>
#include <QString>
#include <QLabel>
#include "global.h"
#include "dialogboxlabel.h"

DialogBoxLabel::DialogBoxLabel() : QLabel(Global::mainWin) {
    this->setText(QString::fromStdString(""));
    this->setGeometry(0,255,600,50);
}
