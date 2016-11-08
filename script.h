#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>
#include <fstream>
#include "scriptline.h"

class Script {
public:
    Script(std::string p);
    bool getNextLine(Dialog * &sl);

protected:
    int numLines;
    std::string path;
    std::ifstream * file;
    Dialog * start, * line;

    //funtions used when parsing the file
    void parse();
    int countNumLines();
    int tenToThePowerOf(int i);
};

#endif // SCRIPT_H
