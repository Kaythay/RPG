#include <iostream>
#include <string>
#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QBitmap>
#include "global.h"
#include "scriptline.h"
#include "unitimage.h"

#define UNIT_IMAGE_PATH "C:\\Users\\Kathy\\Desktop\\RPG\\res\\img\\unit\\"
#define BLANK_IMAGE_PATH "C:\\Users\\Kathy\\Desktop\\RPG\\res\\img\\blank.png"

UnitImage::UnitImage(DialogConstants::sideOfScreen side) : QWidget(Global::mainWin){
    this->side = side;

    this->scene = new QGraphicsScene();
    this->view  = new QGraphicsView(this->scene);
    this->view->setFrameStyle(QFrame::NoFrame);
    this->view->setStyleSheet(QString("background-color: transparent;"));
    this->mapItem = new QGraphicsPixmapItem();
    this->setStyleSheet("background-color: transparent;");

    this->hide();
}

bool UnitImage::update(std::string n, std::string e){
    std::string s = UNIT_IMAGE_PATH;
    s.append(n);
    s.append("\\");
    s.append(e);
    s.append(".png");

    std::cout << s << std::endl;

    QPixmap map(QString::fromStdString(s));
    this->mapItem->setPixmap(map);
    this->scene->addItem(this->mapItem);
    this->view->show();
    return true;
}

bool UnitImage::clear(){
    QPixmap map(QString::fromStdString(BLANK_IMAGE_PATH));
    this->mapItem->setPixmap(map);
    this->scene->addItem(this->mapItem);
    this->view->show();
    return true;
}
