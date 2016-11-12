#include <iostream>
#include <string>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "global.h"
#include "screen.h"
#include "script.h"
#include "unitimage.h"

Screen::Screen(std::string backgrndPath, std::string scrptPath) : QWidget(Global::mainWin){
    this->busy = true;

    this->script = new Script(scrptPath);
    this->resize(SCREEN_X, SCREEN_Y);

    //set up properties needed for showing the background
    this->backgrndScene = new QGraphicsScene(Global::mainWin);
    this->backgrndView  = new QGraphicsView(this->backgrndScene, Global::mainWin);
    this->backgrndMap   = new QGraphicsPixmapItem(QPixmap(QString::fromStdString(backgrndPath)));
    this->backgrndScene->addItem(this->backgrndMap);
    this->backgrndView->lower();
    this->backgrndView->show();

    this->box = new DialogBox();
    this->unitImg = new UnitImage(DialogConstants::LEFT);

    this->show();
    std::cout << "123456" << std::endl;

    this->busy = false;
}

bool Screen::updateFrame(){
    this->busy = true;

    Dialog * sl;

    //get the next line from the script and store it in sl
    //if there are no more lines left, the method will return a false
    if (this->script->getNextLine(sl)){

        //update unit image
        this->unitImg->update(sl->getSpeaker(), sl->getEmotion());

        //update dialog box
        this->box->update(sl->getSpeaker(), sl->getWords());

        this->busy = false;
        return true;
    } else {
        //script is done, can hide the dialog box and unit images
        this->busy = false;
        this->box->remove();
        return false;
    }
}
