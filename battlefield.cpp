#include <iostream>
#include <QWidget>
#include "global.h"
#include "screen.h"
#include "battlefield.h"
#include "ui_battlefield.h"
#include "tile.h"

Battlefield::Battlefield() : Screen(EXAMPLE_BATTLEFIELD_BACKGROUND, EXAMPLE_SCRIPT), ui(new Ui::Battlefield) {
    ui->setupUi(this);
    this->setupTiles();
}

/** Constructs all tiles in the Battlefield, including specifiying dimensions, image, etc.
 * See the tile::setWidgetsGeo for more detail. */
bool Battlefield::setupTiles(){
    for (int a = 0; a < (SCREEN_Y/TILE_DIMENSION); a++){
        for (int b = 0; b < (SCREEN_X/TILE_DIMENSION); b++){
            this->tile[a][b] = new Tile(a, b);
        }
    }
    return true;
}

Battlefield::~Battlefield()
{
    delete ui;
}
