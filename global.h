#ifndef COMMON_H
#define COMMON_H

#include <QObject>
#include <QWidget>
#include "player.h"
#include "glass.h"
#include "screen.h"

class Global : public QObject
{
    Q_OBJECT
public:
    explicit Global(QObject *parent = 0);
    static Player * player;
    static Glass * mainW;

signals:

public slots:
};

#endif // COMMON_H
