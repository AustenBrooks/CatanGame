#ifndef PLAYERS_H
#define PLAYERS_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Players{
    public:
        int wood;
        int bricks;
        int grain;
        int wool;
        int ore;
        int victoryPoints;
        int breaker;
        vector<int> ownedTiles;
        vector<int> upgradeTiles;
        
        // ADDED FUNCTIONS
        void print();
        string getName();
        void setName(string);
        Players();
        Players(int);
        void addTile(int);
        
    private:
        string playerNames; 
    };

#endif