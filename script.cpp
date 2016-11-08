#include <iostream>
#include <string>
#include <fstream>
#include "script.h"
#include "scriptline.h"

Script::Script(std::string p) {
    this->path = p;
    this->file = new std::ifstream();
    this->numLines = this->countNumLines();
    this->parse();
}

/** Get the string from the file and create a new Scriptline object using that string. Repeat this until the end of the file
 * is reached. The result is a linked list of Dialog objects containing the script for the conversation.*/
void Script::parse(){
    //temporary string used to hold the input from the file
    std::string s;

    this->file->open(this->path);

    if( this->file->good() ){
        //first need to start the linked list
        getline( *(this->file), s );
        this->line = new Dialog(s);

        //get the first actual Dialog of the script
        getline(*(this->file), s);
        this->line->setNext(s);
        this->line = this->line->getNext();

        //keep a reference to the beginning of the list, but skipping over the unesscary first line of the file
        this->start = this->line;

        //then set up each remaining element of the list
        for (int counter = 0; counter < (this->numLines-1); counter++){
            getline(*(this->file), s);
            this->line->setNext(s);
            this->line = this->line->getNext();
        }
    } else {
        //could not open file, handle error here
        std::cerr << "ERROR: could not open file " << this->path;
    }


    this->file->close();
    //set line to point back to the beginning of the script
    this->line = this->start;
    return;
}

/** Count and return the number of lines in the file. The first line of the file is in the format '//<number of lines>'.
 * Thus, we just need to parse for <number of lines> and return it as an integer. */
int Script::countNumLines(){
    std::string s = "";
    int i = 0, len = 0;

    this->file->open(this->path);
    getline(*(this->file), s);
    this->file->close();

    len = (int) (s.length());

    //start with a counter of 2 to skip the "//" at the beginning
    for (int counter = 2; counter < len; counter++){
        //need to subtract 2 from (len - counter) because counter starts at 2
        i += (s[counter] - 48)*tenToThePowerOf(len - counter - 2);
    }
    return i;
}

/** Pass an exponent, the function will return 10^<exponent> */
int Script::tenToThePowerOf(int i){
    int value = 1;
    for (int counter = 1; counter < i; counter++){
        value *=10;
    }
    return value;
}

/** points the given Dialog object to the next Dialog that needs to be displayed/implemented. */
bool Script::getNextLine(Dialog * &sl){
    if (this->line == NULL){
        return false;
    } else {
        sl = this->line;
        this->line = this->line->getNext();
        return true;
    }
}
