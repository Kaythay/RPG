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
#include "dialogboxlabel.h"

class DialogBox : public QTextEdit
{
public:
    DialogBox();
    bool update(std::string speaker, std::string words);
    bool remove();
    void mouseReleaseEvent(QMouseEvent *event);

protected:
    DialogBoxLabel * label;

};

#endif // SPEECHBOX_H
