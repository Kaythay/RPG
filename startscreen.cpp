#include <iostream>
#include <string>
#include <QWidget>
#include "global.h"
#include "screen.h"
#include "startscreen.h"
#include "ui_startscreen.h"
#include "playercreatescreen.h"
#include "ui_playercreatescreen.h"

StartScreen::StartScreen(Global &g) : Screen(EXAMPLE_BACKGROUND, EXAMPLE_SCRIPT, g), ui(new Ui::StartScreen) {
    ui->setupUi(this);

    //don't react to user input except for the connections listed below
    this->busy = true;

    //when user hit start button, the game goes to the 'create player' Screen
    connect(ui->startButton, SIGNAL (clicked(bool)), this, SLOT (nextScreen()));
}

StartScreen::~StartScreen() {
    delete ui;
}

void StartScreen::nextScreen(){
    /* set up next Screen */
    PlayerCreateScreen * next = new PlayerCreateScreen(*(this->g));
    next->show();
    delete this;
}
