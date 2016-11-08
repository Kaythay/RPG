#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <string>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWidget>
#include "global.h"
#include "screen.h"
#include "tile.h"

namespace Ui { class Battlefield; }

class Battlefield : public Screen {
    Q_OBJECT

public:
    explicit Battlefield(Global &g);
    ~Battlefield();

private:
    Ui::Battlefield *ui;
    Tile * tile[SCREEN_Y/TILE_DIMENSION][SCREEN_X/TILE_DIMENSION];

    bool setupTiles();
};

#endif // BATTLEFIELD_H
