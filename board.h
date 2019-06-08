#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

class Tile{
    protected:
    string player;
    
    public:
    int tileType;
    bool isUpgraded;
    bool isOccupied;
    int number;
    Tile();
    virtual string render(int);
    void buySettlement(string);
    void upgradeSettlement();
};
class Forest : public Tile{
    public:
    Forest(int);
    string render(int);
};
class Hills : public Tile{
    public:
    Hills(int);
    string render(int);
};
class Field : public Tile{
    public:
    Field(int);
    string render(int);
};
class Pasture : public Tile{
    public:
    Pasture(int);
    string render(int);
};
class Mountain : public Tile{
    public:
    Mountain(int);
    string render(int);
};

#endif