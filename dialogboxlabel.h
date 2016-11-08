#ifndef SPEECHBOXLABEL_H
#define SPEECHBOXLABEL_H

#include <string>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include "global.h"

class DialogBoxLabel : public QLabel
{
public:
    DialogBoxLabel(Global &g);
};

#endif // SPEECHBOXLABEL_H
