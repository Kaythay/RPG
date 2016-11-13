#include <iostream>
#include <string>
#include <QWidget>
#include <QObject>
#include <QString>
#include <QLabel>
#include "global.h"
#include "textboxlabel.h"

TextBoxLabel::TextBoxLabel() : QLabel(Global::mainWin) {
    this->setText(QString::fromStdString(""));
    this->setGeometry(0,255,600,50);
}

void TextBoxLabel::mouseReleaseEvent(QMouseEvent *event){
    event->ignore();
    return;
}
