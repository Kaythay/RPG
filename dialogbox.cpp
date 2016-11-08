#include <iostream>
#include <string>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QMouseEvent>
#include "global.h"
#include "dialogbox.h"

DialogBox::DialogBox(Global &g) : QTextEdit() {
    this->setReadOnly(true);
    this->setGeometry(0,300,600,150);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->label = new DialogBoxLabel(g);
}

void DialogBox::mouseReleaseEvent(QMouseEvent *event){
    event->ignore();
    std::cout << "hello" << std::endl;
    return;
}

bool DialogBox::update(std::string speaker, std::string words){
    this->setText(QString::fromStdString(words));
    this->label->setText(QString::fromStdString(speaker));

    this->raise();
    this->label->raise();

    this->label->show();
    this->show();
    return true;
}
