#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    explicit Item(std::string n);

    //getter functions
    int getAcc();
    int getPower();
    std::string getName();

    //setter functions
    void setName(std::string newName);
    void reduceUses(int i = 1);

protected:
    std::string name;
    int uses, range, power, acc;
};

#endif // ITEM_H
