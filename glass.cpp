#include <iostream>
#include <string>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QMouseEvent>
#include "glass.h"
#include "screen.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    this->resize(SCREEN_X, SCREEN_Y);
    this->setStyleSheet(QString("background-color: transparent;"));
    this->show();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    event->accept();
    std::cout << "here" << std::endl;
}
