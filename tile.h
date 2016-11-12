#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string>
#include <QObject>
#include <QWidget>
#include "global.h"

#define TILE_DIMENSION 30

class Tile : public QObject
{
    Q_OBJECT
public:
    explicit Tile(int a, int b);

protected:
    QWidget * widget;

signals:

public slots:
};

#endif // TILE_H
