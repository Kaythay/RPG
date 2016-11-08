#ifndef SCRIPTLINE_H
#define SCRIPTLINE_H

#include <string>
#include <fstream>

namespace DialogConstants {
    enum sideOfScreen{
        LEFT,
        RIGHT
    };
    enum unitType{
        PLAYER,
        SHADOW,
        NORMAL
    };
}

#define PROPERTY_DIV '|'
#define PROPERTY_DIV_LEN 1 //this constant must be the number of characters in PROPERTY_DIV

class Dialog {
public:
    Dialog(std::string s);
    bool parse(std::string s);

    //setter method
    bool setNext(std::string s);

    // getter methods
    bool readable();
    std::string getSpeaker();
    std::string getWords();
    std::string getEmotion();
    DialogConstants::sideOfScreen getSide();
    Dialog * getNext();

protected:
    bool read;
    std::string speaker, words, emotion;
    DialogConstants::sideOfScreen side;
    Dialog * next;

    std::string find(std::string input, int &ref, char end = PROPERTY_DIV);

    //need a specific function for finding the side, since side is an enum type
    DialogConstants::sideOfScreen findSide(std::string input, int &ref, char end = PROPERTY_DIV);
};

#endif // SCRIPTLINE_H
