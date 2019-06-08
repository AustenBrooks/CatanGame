#include "card.h"

void DevelopmentCards::action(int cardNum, Players *playername){ // gets called second to actually perform card action
    
    
    switch (cardNum){ // finds which card is drawn and reads reward
    
        case 1 : cout << "Congrats! You have drawn the Library card!" << endl;
        cout << "You will gain 1 Victory point." << endl;
        cout << "Victory points before: " << playername->victoryPoints << endl;
        playername->victoryPoints = playername->victoryPoints + 1;
            break;
            
            
        case 2 : cout << "Congrats! You have drawn the University card!" << endl;
        cout << "You will gain 1 Victory point." << endl;
        cout << "Victory points before: " << playername->victoryPoints << endl;
        playername->victoryPoints = playername->victoryPoints + 1;
            break;
            
            
        case 3 : cout << "Congrats! You have drawn the Town Hall card!" << endl;
        cout << "You will gain 1 Victory point." << endl;
        cout << "Victory points before: " << playername->victoryPoints << endl;
        playername->victoryPoints = playername->victoryPoints + 1;
            break;
            
            
        case 4 : cout << "Congrats! You have drawn the Harvest Bounty card!" << endl;
        cout << "You will gain 2 resource of each type." << endl;
        playername->wood = playername->wood + 2;
        playername->bricks = playername->bricks + 2;
        playername->grain = playername->grain + 2;
        playername->wool = playername->wool + 2;
        playername->ore = playername->ore + 2;
            break;
            
            
        case 5 : cout << "Congrats! You have drawn the Knight card!" << endl; 
        cout << "You will gain 1 resource from a player of your choice." << endl;
        playername->breaker = -15;
            break;
            
            
        default : cout << "Error" << endl;
            break;
    }
    
};


void DevelopmentCards::drawCard(Players *playerName){ // gets called by int main and checks requirements
    playerName->ore = playerName->ore - 1; // subtracts the resource
    playerName->wool = playerName->wool - 1;
    playerName->grain = playerName->grain - 1;
    
    srand(time(0)); // shuffle cards using pseudo random number generator 
    int randomNum = (rand() % 20);
    int temp = deckArray[randomNum]; 
    
    action(temp, playerName); // calls action function
    
    
    

};


void DevelopmentCards::robberCard(Players *robber, Players *victim){
    cout << "Their current inventory: \n" ;
        srand(time(0)); // shuffle cards using pseudo random number generator 
        int temp = 0;
        victim->print();
            cout << endl;
            
        while (temp == 0){ 
            int randomNum = (rand() % 5);
            if (victim->wood == 0 && victim->bricks == 0 && victim->grain == 0 && victim->wool == 0 && victim->ore == 0){
                randomNum = 7;
            }switch (randomNum){
                case 0 : 
                if (victim->wood > 0){
                    cout << "You will take 1 wood from them \n";
                    robber->breaker = 0;
                    robber->wood = robber->wood + 1;
                    temp = 1;
                }
                else {cout << "";}
                break;
                
                case 1 : 
                if (victim->bricks > 0){
                    cout << "You will take 1 bricks from them \n";
                    robber->breaker = 1;
                    robber->bricks = robber->bricks + 1;
                    temp = 1;
                }
                else {cout << "";}
                break;
                
                case 2 : 
                if (victim->grain > 0){
                    cout << "You will take 1 grain from them \n";
                    robber->breaker = 2;
                    robber->grain = robber->grain + 1;
                    temp = 1;
                }
                else {cout << "";}
                break;
                
                case 3 : 
                if (victim->wool > 0){
                    cout << "You will take 1 wool from them \n";
                    robber->breaker = 3;
                    robber->wool = robber->wool + 1;
                    temp = 1;
                }
                else {cout << "";}
                break;
                
                case 4 : 
                if (victim->ore > 0){
                    cout << "You will take 1 ore from them \n";
                    robber->breaker = 4;
                    robber->ore = robber->ore + 1;
                    temp = 1;
                }
                else {cout << "";}
                break;
                
                case 7 :
                cout << "They have no resources, so you gain 0 resources \n";
                temp = 1;
                break;
            }
        }
        
};

void DevelopmentCards::stealing(Players *robber, int temp){
    int temp2;
    switch(temp){
        case 0 : 
        temp2 = robber->wood - 1;
        robber->wood = temp2;
        break;
        
        case 1 :
        temp2 = robber->bricks - 1;
        robber->bricks = temp2;
        break;
        
        case 2 : 
        temp2 = robber->grain - 1;
        robber->grain = temp2;
        break;
        
        case 3 : 
        temp2 = robber->wool - 1;
        robber->wool = temp2;
        break;
        
        case 4 : 
        temp2 = robber->ore - 1;
        robber->ore = temp2;
        break;
    }
    
};

