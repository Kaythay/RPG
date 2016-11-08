#include <iostream>
#include <string>
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QBitmap>
#include "global.h"
#include "scriptline.h"
#include "unitimage.h"

#define UNIT_IMAGE_PATH "C:\\Users\\Kathy\\Documents\\RPG\\res\\img\\unit\\"
#define BLANK_IMAGE_PATH "C:\\Users\\Kathy\\Documents\\RPG\\res\\img\\blank.png"

UnitImage::UnitImage(DialogConstants::sideOfScreen side, Global &g) : QWidget(g.mainW){
    this->g = &g;
    this->side = side;

    this->scene = new QGraphicsScene(this->g->mainW);
    this->view  = new QGraphicsView(this->scene, this->g->mainW);
    this->view->setFrameStyle(QFrame::NoFrame);
    this->mapItem = new QGraphicsPixmapItem();
    this->map = new QPixmap(BLANK_IMAGE_PATH);
    this->map->setMask(this->map->createMaskFromColor(QColor(0, 255, 0)));

    this->hide();
}

bool UnitImage::update(std::string n, std::string e){
    std::string s = UNIT_IMAGE_PATH;
    s.append(n);
    s.append("\\");
    s.append(e);
    s.append(".png");

    this->scene->removeItem(this->mapItem);
    this->map->swap(QPixmap(QString::fromStdString(s)));
    this->mapItem->setPixmap(*this->map);
    this->scene->addItem(this->mapItem);
    this->view->show();
    this->view->lower();
    return true;
}

bool UnitImage::clear(){

    this->scene->removeItem(this->mapItem);
    this->map->swap(QPixmap(BLANK_IMAGE_PATH));
    this->mapItem->setPixmap(*this->map);
    this->scene->addItem(this->mapItem);
    this->view->show();
    return true;
}
