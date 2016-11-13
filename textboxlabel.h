#ifndef SPEECHBOXLABEL_H
#define SPEECHBOXLABEL_H

#include <string>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include "global.h"

class TextBoxLabel : public QLabel
{
public:
    TextBoxLabel();
    void mouseReleaseEvent(QMouseEvent *event);

};

#endif // SPEECHBOXLABEL_H
