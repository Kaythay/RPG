#ifndef SPEECHBOX_H
#define SPEECHBOX_H

#include <iostream>
#include <QObject>
#include <QWidget>
#include <QTextEdit>
#include <QObject>
#include <QWidget>
#include "global.h"
#include "dialog.h"
#include "textboxlabel.h"

class TextBox : public QTextEdit
{
public:
    TextBox();
    void mouseReleaseEvent(QMouseEvent *event);
    bool update(std::string speaker, std::string words);
    bool remove();

protected:
    TextBoxLabel * label;

};

#endif // SPEECHBOX_H
