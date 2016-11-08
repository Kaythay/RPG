#ifndef UNITIMAGE_H
#define UNITIMAGE_H

#include <string>
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "global.h"
#include "scriptline.h"

class UnitImage : public QWidget
{
    Q_OBJECT
public:
    explicit UnitImage(DialogConstants::sideOfScreen side, Global &g);

    bool update(std::string n, std::string e);
    bool clear();

protected:
    Global * g;

    //properties needed for displaying unit sprites
    QGraphicsScene * scene;
    QGraphicsView * view;
    QGraphicsPixmapItem * mapItem;
    QPixmap * map;
    DialogConstants::sideOfScreen side;

signals:

public slots:
};

#endif // UNITIMAGE_H
