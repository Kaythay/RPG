#include <iostream>
#include <string>
#include <QObject>
#include "scriptline.h"

//TODO: make exeption for whenever a file line is in the wrong format

Dialog::Dialog(std::string s) {
    this->parse(s);
    this->next = NULL;
}

/** Method takes the string from the constructor to parse for the speaker, words, and emotion. */
bool Dialog::parse(std::string s){
    if ((s[0] == '/' && s[1] == '/')){
        this->read = false;
    } else {
        this->read = true;
        int ref = 0;
        this->speaker = this->find(s, ref);
        this->words   = this->find(s, ref);
        this->emotion = this->find(s, ref);
        this->side    = this->findSide(s, ref);
    }

    return true;
}

/** Returns the substring from the input string, starting from the 'ref' position
 * and ending whenever a char equals the 'end' char or null */
std::string Dialog::find(std::string input, int &ref, char end){
    std::string temp = "";
    while ((input[ref] != end) && (input[ref] != '\0')){
        temp.push_back(input[ref]);
        ref++;
    }
    ref++;
    return temp;
}

DialogConstants::sideOfScreen Dialog::findSide(std::string input, int &ref, char end){
    std::string s = this->find(input, ref, end);

    if (s.compare("LEFT")) {
        return DialogConstants::LEFT;
    } else {
        //assume right for invalid inputs
        return DialogConstants::RIGHT;
    }
}

/** set the next property as a new Dialog */
bool Dialog::setNext(std::string s){
    this->next = new Dialog(s);
    return true;
}

bool Dialog::readable(){
    return this->read;
}

Dialog * Dialog::getNext(){
    return this->next;
}

std::string Dialog::getSpeaker(){
   return this->speaker;
}

std::string Dialog::getWords(){
    return this->words;
}

std::string Dialog::getEmotion(){
    return this->emotion;
}
