#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "global.h"
#include "script.h"
#include "dialogbox.h"
#include "dialogboxlabel.h"
#include "unitimage.h"

#define EXAMPLE_BATTLEFIELD_BACKGROUND "C:\\Users\\Kathy\\Desktop\\RPG\\res\\img\\background\\battle\\exampleBattlefield.png"
#define EXAMPLE_BACKGROUND             "C:\\Users\\Kathy\\Desktop\\RPG\\res\\img\\background\\cutscene\\exampleBackground.png"
#define EXAMPLE_SCRIPT                 "C:\\Users\\Kathy\\Desktop\\RPG\\res\\script\\cutscene\\exampleScript.txt"
#define SCREEN_Y 450
#define SCREEN_X 600


class Screen : public QWidget {
    Q_OBJECT
public:
    explicit Screen(std::string backgrndPath, std::string scrptPath);
    bool updateFrame();
    bool isBusy();

protected:
    Script * script;

    //boolean to indicate if screen should ignore user input
    bool busy;

    //properties and methods needed for displaying the background
    std::string backgrndPath;
    QGraphicsScene * backgrndScene;
    QGraphicsView * backgrndView;
    QGraphicsPixmapItem * backgrndMap;

    //properties needed for dsplaying text and unit images
    DialogBox * box;
    UnitImage * unitImg;



signals:

public slots:
};

#endif // SCREEN_H
