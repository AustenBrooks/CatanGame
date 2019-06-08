#ifndef CARDS_H
#define CARDS_H

#include "players.h"

#include <vector>
#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;


class DevelopmentCards{ 
    public: 
        void action(int, Players *playerName);
        void drawCard(Players *playerName);
        int deckArray[20] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5}; // array of cards
        void robberCard(Players *robber, Players *victim);
        void stealing(Players *robber, int);
        
};


#endif