#include <iostream>
#include <string>
#include "global.h"
#include "screen.h"
#include "forestscreen.h"
#include "ui_forestscreen.h"
#include "player.h"

ForestScreen::ForestScreen(Global &g) : Screen(EXAMPLE_BACKGROUND, EXAMPLE_SCRIPT, g), ui(new Ui::ForestScreen){
    ui->setupUi(this);
    this->updateFrame();

}

ForestScreen::~ForestScreen(){
    delete ui;
}
