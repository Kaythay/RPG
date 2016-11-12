#include <iostream>
#include <string>
#include <QWidget>
#include <QObject>
#include <QString>
#include "tile.h"

Tile::Tile(int a, int b) : QObject(Global::mainWin){
    this->widget = new QWidget();

    /* make sure the widget's geometry is a square. The function also sets the (x,y) location of the widget */
    this->widget->setGeometry((TILE_DIMENSION*b), (TILE_DIMENSION*a), TILE_DIMENSION,TILE_DIMENSION);
    this->widget->show();
}
