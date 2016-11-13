#include <iostream>
#include <string>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QMouseEvent>
#include "mainwin.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    this->resize(SCREEN_X, SCREEN_Y);
    this->show();
}
