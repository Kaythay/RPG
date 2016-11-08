#ifndef SPEECHBOX_H
#define SPEECHBOX_H

#include <iostream>
#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QObject>
#include <QWidget>
#include "global.h"
#include "scriptline.h"
#include "speechboxlabel.h"

class DialogBox : public QTextEdit
{
public:
    DialogBox(Global &g);
    bool update(std::string speaker, std::string words);
    void mouseReleaseEvent(QMouseEvent *event);

protected:
    DialogBoxLabel * label;

};

#endif // SPEECHBOX_H
