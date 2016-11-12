#include <iostream>
#include <string>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QMouseEvent>
#include "glass.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    this->setStyleSheet(QString("background-color: transparent;"));
    this->raise();
}
