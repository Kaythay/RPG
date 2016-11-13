#include <iostream>
#include <string>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QMouseEvent>
#include <QTextEdit>
#include <QLabel>
#include "global.h"
#include "textbox.h"

TextBox::TextBox() : QTextEdit(Global::mainWin) {
    this->setReadOnly(true);
    this->setGeometry(0,300,600,150);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->label = new TextBoxLabel();

    this->hide();
    this->label->hide();
}

void TextBox::mouseReleaseEvent(QMouseEvent *event){
    event->ignore();
    return;
}

bool TextBox::update(std::string speaker, std::string words){
    this->setText(QString::fromStdString(words));
    this->label->setText(QString::fromStdString(speaker));
    this->label->show();
    this->show();

    this->activateWindow();
    this->label->raise();
    this->raise();

    return true;
}

bool TextBox::remove(){
    this->hide();
    this->label->hide();
    return true;
}
