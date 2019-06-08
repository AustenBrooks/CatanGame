#include "players.h"

Players::Players(){
    this->wood = 10;
    this->bricks = 10;
    this->grain = 10;
    this->wool = 10;
    this->ore = 10;
    this->victoryPoints=0;
}

void Players::print() {
    cout << "wood = " << wood << endl;
    cout << "bricks = " << bricks << endl;
    cout << "grain = " << grain << endl;
    cout << "wool = " << wool << endl;
    cout << "ore = " << ore << endl;
    cout << "victory points = " << victoryPoints << endl;    
};

void Players::setName(string playerNames){
    this-> playerNames = playerNames;
};

string Players::getName(){
    return this-> playerNames;
}

void Players::addTile(int tile){
    ownedTiles.push_back(tile);
}