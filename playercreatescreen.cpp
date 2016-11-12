#include <iostream>
#include <string>
#include "global.h"
#include "screen.h"
#include "playercreatescreen.h"
#include "ui_playercreatescreen.h"
#include "forestscreen.h"
#include "player.h"

PlayerCreateScreen::PlayerCreateScreen() : Screen(EXAMPLE_BACKGROUND, EXAMPLE_SCRIPT), ui(new Ui::PlayerCreateScreen) {
    ui->setupUi(this);

    //don't react to user input except for the connections listed below, and events created by Qt Designer
    this->busy = true;

    //when user hits OK button, go to the next Screen
    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(done()));
}

PlayerCreateScreen::~PlayerCreateScreen() {
    delete ui;
}

/** When player hits the OK button, program will check whether the inputs are valid. If they are valid,
 * the function will create a new player object and go to the next Screen.
 * INPUT= none
 * OUTPUT= none*/
void PlayerCreateScreen::done() {
    bool nB = false,
         gB = false;

    //Get the name from the ui.
    this->n = ui->nameInput->text().toStdString();

    //Check if name is valid.
    nB = this->isNameValid();

    //Check if gender is properly selected, and determine which gender was selected.
    gB = this->isGenderValid();

    if (nB && gB){
        ForestScreen * next = new ForestScreen();
        next->show();

        delete this;
    }
}


/** Function used to check whether the player has entered a valid name.
 * INTPUT(S)= none
 * OUTPUT= bool: true if valid, false otherwise*/
bool PlayerCreateScreen::isNameValid(){

    if (this->n.empty()) {
        //name is not valid if the player did not enter a name
        ui->nameErrorLabel->setText("Need to enter a name!");
        return false;
    } else if (this->n.length() > 16) {
        //name is not valid if name is more than 16 characters
        ui->nameErrorLabel->setText("Name must be less than 16 characters!");
        return false;
    } else {
        ui->nameErrorLabel->clear();
        return true;

    }
}

/** Function that determines gender by determining which radio button is checked. Also validates selected gender (invalid
 * if it does not match the predefined gender constants.
 * INPUT(S)= none
 * OUTPUT= bool: true if gender is valid, false otherwise*/
bool PlayerCreateScreen::isGenderValid(){
    if(ui->femaleRadioBtn->isChecked()) {
        this->gen = unit_constants::FEMALE;
        ui->genderErrorLabel->clear();
        return true;
    } else if (ui->maleRadioBtn->isChecked()){
        this->gen = unit_constants::MALE;
        ui->genderErrorLabel->clear();
        return true;
    } else {
        //invalid gender selected
        ui->genderErrorLabel->setText("Need to choose a gender!");
        return false;
    }
}
