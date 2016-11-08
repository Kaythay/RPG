#include <iostream>
#include <string>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "global.h"
#include "screen.h"
#include "script.h"
#include "unitimage.h"

Screen::Screen(std::string backgrndPath, std::string scrptPath, Global &g) : QWidget(g.mainW){
    this->busy = true;

    this->g = &g;
    this->script = new Script(scrptPath);
    this->resize(SCREEN_X, SCREEN_Y);

    //set up properties needed for showing the background
    this->backgrndScene = new QGraphicsScene(this->g->mainW);
    this->backgrndView  = new QGraphicsView(this->backgrndScene, this->g->mainW);
    this->backgrndMap   = new QGraphicsPixmapItem(QPixmap(QString::fromStdString(backgrndPath)));
    this->backgrndScene->addItem(this->backgrndMap);
    this->backgrndView->lower();
    this->backgrndView->show();

    this->box = new DialogBox(*this->g);
    this->box->setParent(this);
    this->unitImg = new UnitImage(DialogConstants::LEFT, g);

    this->busy = false;
}

void Screen::mouseReleaseEvent(QMouseEvent *event){
    event->accept();

    //if the screen is not busy, update the gui
    //otherwse, do nothing
    if (!this->busy){
        this->updateFrame();
    }



    return;
}

bool Screen::updateFrame(){
    this->busy = true;

    Dialog * sl;

    //get the next line from the script and store it in sl
    //if there are no more lines left, the method will returna false
    if (this->script->getNextLine(sl)){

        //update unit image
        this->unitImg->update(sl->getSpeaker(), sl->getEmotion());

        //update dialog box
        this->box->update(sl->getSpeaker(), sl->getWords());

        this->busy = false;
        return true;
    } else {
        //script is done
        this->busy = false;
        return false;
    }
}
