#ifndef COMMON_H
#define COMMON_H

#include <QObject>
#include <QWidget>
#include "player.h"

class Global : public QObject
{
    Q_OBJECT
public:
    explicit Global(QObject *parent = 0);
    Player * player;
    QWidget * mainW;

signals:

public slots:
};

#endif // COMMON_H
