#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <string>

#include "card.h"
#include "players.h"
#include "board.h"

using namespace std;


void buildBoard(vector<Tile*> &board, int numTiles){
    srand(time(0));
    
    for(int i=0;i<numTiles;++i){
        int tileType = rand() %5;
        int number=rand()%11+2;
        if(tileType==0)
            board.push_back(new Forest(number));
        if(tileType==1)
            board.push_back(new Hills(number));
        if(tileType==2)
            board.push_back(new Field(number));
        if(tileType==3)
            board.push_back(new Pasture(number));
        if(tileType==4)
            board.push_back(new Mountain(number));
    }
}

int main(){
    //Random number generator
    srand(time(0));
    //Variables
    bool canbuy; // determines if the player can / wants to buy a dev card
    string devCardAns;
    int stealFrom = -1;
    string tempName;
    vector<Tile*> board;
    int numPlayers;
    int temp;
    int die1;
    int die2;
    int NUM_ROWS;
    int NUM_COLS;
    //Start of game
    
    cout << "GAME OF CATAN" << endl;
    cout<< "How many rows for the board?"<<endl;
    cin>>NUM_ROWS;
    cout<<"How many columns for the board?"<<endl;
    cin>>NUM_COLS;
    cout << "How many players? \n";
    cin >> numPlayers;
    int numTiles=NUM_COLS*NUM_ROWS;
    
    DevelopmentCards card; // initializes card class
    vector<Players*> gameFlow;
    buildBoard(board, numTiles);
    
    for(int i = 0; i < numPlayers; i++){
        gameFlow.push_back(new Players);
        cout << "Player " << i + 1 << " what is your name? ";
        cin >> tempName;
        gameFlow.at(i)->setName(tempName);
        cout << endl;
        if(tempName.size() < 12){
            while(tempName.size()<12){
                tempName.push_back(' ');
            }
        	gameFlow.at(i)->setName(tempName);
    	}
        else{
        	tempName = tempName.substr(0,12);
        	gameFlow.at(i)->setName(tempName);
    	}
    }
    for(int i=0;i<numPlayers;i++){
        int tile=rand()%numTiles;
        while(board.at(tile)->isOccupied){
            tile=rand()%numTiles;
        }
        board.at(tile)->buySettlement(gameFlow.at(i)->getName());
        gameFlow.at(i)->addTile(tile);
    }
    
    int maxPoints = 0;
    int currentPlayer=0;
    
    while(maxPoints < 10){
        if(currentPlayer>numPlayers-1){
            currentPlayer=0;
        }
        
        //Renders Board
        for(int k=0; k<NUM_ROWS;k++){
            for(int i = 0; i <= 7; i++){
                for(int j = k*NUM_COLS; j < (k+1)*NUM_COLS; j++){
                    cout << board.at(j)->render(i) << " ";
                }
                cout<<endl;
            }
        }
        cout<<gameFlow.at(currentPlayer)->getName()<<" 's turn"<<endl;
        gameFlow.at(currentPlayer)->print();
        die1=rand()%6+1;
        die2=rand()%6+1;
        int roll=die1+die2;
        cout<<"You rolled a "<<roll<<endl;
        for(int i=0; i<gameFlow.at(currentPlayer)->ownedTiles.size();++i){
            if(roll==board.at(gameFlow.at(currentPlayer)->ownedTiles.at(i))->number){
                switch(board.at(gameFlow.at(currentPlayer)->ownedTiles.at(i))->tileType){
                    case 0: 
                        gameFlow.at(currentPlayer)->wood++;
                        cout<<"You gain +1 wood"<<endl;
                        break;
                    case 1:
                        gameFlow.at(currentPlayer)->bricks++;
                        cout<<"You gain +1 bricks"<<endl;
                        break;
                    case 2:
                        gameFlow.at(currentPlayer)->grain++;
                        cout<<"You gain +1 grain"<<endl;
                        break;
                    case 3:
                        gameFlow.at(currentPlayer)->wool++;
                        cout<<"You gain +1 wool"<<endl;
                        break;
                    case 4:
                        gameFlow.at(currentPlayer)->ore++;
                        cout<<"You gain +1 ore"<<endl;
                        break;
                }
            }
        }
        int choice=-1;
        while(choice!=4){
            cout<< "Do you want to buy a settlement (0), upgrade a settlement (1), trade resources (2), buy a develepment card (3), or pass your turn (4)?"<<endl;
            cin>>choice;
            while(choice<0||choice>4){
                cout<<"Invalid Choice"<<endl;
                cin>>choice;
            }
            
            if(choice==0){
                int row;
                int col;
                bool isChoosing=true;
                while(isChoosing){
                    if(gameFlow.at(currentPlayer)->wood>0 && gameFlow.at(currentPlayer)->bricks>0 && gameFlow.at(currentPlayer)->grain>0 && gameFlow.at(currentPlayer)->wool>0){
                        cout<<"Choose a tile adjacent to one of your settlements"<<endl<<"Enter the row (0-"<<NUM_ROWS-1<<"): "<<endl;
                        cin>>row;
                        while(row>NUM_ROWS-1||row<0){
                            cout<<"invalid Choice"<<endl;
                            cin>>row;
                        }
                        cout<<"Enter the column (0-"<<NUM_COLS-1<<"): "<<endl;
                        cin>>col;
                        while(col>NUM_COLS-1||col<0){
                            cout<<"invalid Choice"<<endl;
                            cin>>col;
                        }
                        
                        int tile = row*NUM_COLS+col;
                        
                        // check adjacent
                        if((board.at(tile)->isOccupied) == false){
                            
                            isChoosing=false;
                        }
                        else{
                            cout<<"Tile is occupied"<<endl<<endl;
                        }
                        if(!isChoosing){
                            isChoosing=true;
                            
                            for(int i=0;i<gameFlow.at(currentPlayer)->ownedTiles.size();++i){
                                if(gameFlow.at(currentPlayer)->ownedTiles.at(i)-1==tile)
                                    isChoosing=false;
                                if(gameFlow.at(currentPlayer)->ownedTiles.at(i)+1==tile)
                                    isChoosing=false;
                                if(gameFlow.at(currentPlayer)->ownedTiles.at(i)-NUM_COLS==tile)
                                    isChoosing=false;
                                if(gameFlow.at(currentPlayer)->ownedTiles.at(i)+NUM_COLS==tile)
                                    isChoosing=false;
                            }
                            if(isChoosing)
                                cout<<"Tile is not adjacent to owned settlement"<<endl<<endl;
                        }
                        if(!isChoosing){
                            board.at(tile)->buySettlement(gameFlow.at(currentPlayer)->getName());
                            gameFlow.at(currentPlayer)->addTile(tile);
                            
                            gameFlow.at(currentPlayer)->wood--;
                            gameFlow.at(currentPlayer)->bricks--;
                            gameFlow.at(currentPlayer)->grain--;
                            gameFlow.at(currentPlayer)->wool--;
                            gameFlow.at(currentPlayer) ->victoryPoints ++;
                            
                            gameFlow.at(currentPlayer)->print();
                        }
                    }
                     else
                        cout<< "You cant afford a settlement"<<endl;
                }
                
                for(int k=0; k<NUM_ROWS;k++){
                    for(int i = 0; i <= 7; i++){
                        for(int j = k*NUM_COLS; j < (k+1)*NUM_COLS; j++){
                            cout << board.at(j)->render(i) << " ";
                        }
                        cout<<endl;
                    }
                }
                   
            }else if(choice  == 1){
                int row;
                int col;
                bool wrongChoice=true;
                if( gameFlow.at(currentPlayer)->grain>=3 && gameFlow.at(currentPlayer)-> ore >= 2){
                    while(wrongChoice){
                        cout << "Select the row of the settlement you want to upgrade(0-"<<NUM_ROWS-1<<"): "<<endl;
                        cin>>row;
                        while(row>NUM_ROWS-1||row<0){
                            cout<<"Invalid Choice"<<endl;
                            cin>>row;
                        }
                        cout<<"Enter the column (0-"<<NUM_COLS-1<<"): "<<endl;
                        cin>>col;
                        while(col>NUM_COLS-1||col<0){
                            cout<<"Invalid Choice"<<endl;
                            cin>>col;
                        }
                        int tile = row*NUM_COLS+col;
                        
                        for(int i=0;i<gameFlow.at(currentPlayer)->ownedTiles.size();++i){
                            if(gameFlow.at(currentPlayer)->ownedTiles.at(i)==tile)
                                wrongChoice=false;
                        }
                        if(wrongChoice){
                            cout<< "Invalid Choice"<<endl;
                        }
                        else{
                            board.at(tile)->upgradeSettlement();
                            gameFlow.at(currentPlayer)->upgradeTiles.push_back(tile);
                        }
                    }
                    
                    for(int k=0; k<NUM_ROWS;k++){
                        for(int i = 0; i <= 7; i++){
                            for(int j = k*NUM_COLS; j < (k+1)*NUM_COLS; j++){
                                cout << board.at(j)->render(i) << " ";
                            }
                            cout<<endl;
                        }
                    }
                }
                else{
                    cout << "You dont have enough resources.(3 grain, 2 ore)\n";
                }
                
                gameFlow.at(currentPlayer) ->victoryPoints ++;
            }else if(choice == 2){
                int tradeChoice = -1;
                int tradeBack = -1;
                bool isTrading=false;
                cout << "What resource would you like to trade with?(0 = ore, 1 = wood, 2 = wool, 3 = grain, 4 = brick)\n";
                cin >> tradeChoice;
                while(tradeChoice <= -1 || tradeChoice >= 5){
                    cout << "Invalid number, try again: \n";
                    cin >> tradeChoice;
                }
                cout << "What resource would you like to get?(0 = ore, 1 = wood, 2 = wool, 3 = grain, 4 = brick)\n";
                cin >> tradeBack;
                while(tradeBack <= -1 || tradeBack >= 5){
                    cout << "Invalid number, try again: \n";
                    cin >> tradeBack;
                }
                
                switch(tradeChoice){
                    case 0:
                        if(gameFlow.at(currentPlayer)->ore>3){
                            gameFlow.at(currentPlayer)->ore = gameFlow.at(currentPlayer)->ore - 3;
                            isTrading=true;
                        }else{
                            cout << "You dont have enough resource.\n";
                            break;
                        }
                    case 1:
                        if(gameFlow.at(currentPlayer)->wood>3){
                            gameFlow.at(currentPlayer)->wood = gameFlow.at(currentPlayer)->wood - 3;
                            isTrading=true;
                        }else{
                            cout << "You dont have enough resource.\n";
                            break;
                        }
                    case 2:
                        if(gameFlow.at(currentPlayer)->wool>3){
                            gameFlow.at(currentPlayer)->wool = gameFlow.at(currentPlayer)->wool - 3;
                            isTrading=true;
                        }else{
                            cout << "You dont have enough resource.\n";
                            break;
                        }
                    case 3:
                        if(gameFlow.at(currentPlayer)->grain>3){
                            gameFlow.at(currentPlayer)->grain = gameFlow.at(currentPlayer)->grain - 3;
                            isTrading=true;
                        }else{
                            cout << "You dont have enough resource.\n";
                            break;
                        }
                    case 4:
                        if(gameFlow.at(currentPlayer)->bricks>3){
                            gameFlow.at(currentPlayer)->bricks = gameFlow.at(currentPlayer)->bricks - 3;
                            isTrading=true;
                        }else{
                            cout << "You dont have enough resource.\n";
                            break;
                        }
                    }
                    if(isTrading){
                        switch(tradeBack){
                            case 0:
                                gameFlow.at(currentPlayer)->ore = gameFlow.at(currentPlayer)->ore  + 1;
                                break;
                            case 1:
                                gameFlow.at(currentPlayer)->wood = gameFlow.at(currentPlayer)->wood  + 1;
                                break;
                            case 2:
                                gameFlow.at(currentPlayer)->wool = gameFlow.at(currentPlayer)->wool  + 1;
                                break;
                            case 3:
                                gameFlow.at(currentPlayer)->grain = gameFlow.at(currentPlayer)->grain  + 1;
                                break;
                            case 4:
                                gameFlow.at(currentPlayer)->bricks = gameFlow.at(currentPlayer)->bricks  + 1;
                                break;
                        }
                    }
            }else if(choice  == 3){
                if (gameFlow.at(currentPlayer)->ore >= 1 && gameFlow.at(currentPlayer)->wool >= 1 && gameFlow.at(currentPlayer)->grain >= 1){
                    canbuy = true;
                }
                else{
                    canbuy = false;
                    cout << "You cannot afford this.\n";
                }
                
                
                if (canbuy == true) {  
                    card.drawCard(gameFlow.at(currentPlayer)); // calls draw card
                    if (gameFlow.at(currentPlayer)->breaker == -15){
                        cout << "What player would you like to steal from? \n";
                        cin >>  stealFrom;
                        stealFrom = stealFrom - 1;
                        while(stealFrom <= -1 || stealFrom > gameFlow.size()){
                            cout << "You didnt select a person.\n";
                            cin >> stealFrom;
                        }
                        
                        
                        card.robberCard(gameFlow.at(currentPlayer), gameFlow.at(stealFrom));
                        temp = gameFlow.at(currentPlayer)->breaker;
                        
                        card.stealing(gameFlow.at(stealFrom), temp);
                        cout << "Current Player's new stats \n";
                        gameFlow.at(currentPlayer)->print();
                        
                    }else{
                        cout << "New inventory: " << endl;
                        gameFlow.at(currentPlayer)->print();
                    }
                }
            }
            for(int i=0; i<numPlayers;i++){
                if(gameFlow.at(i)->victoryPoints>maxPoints){
                    maxPoints=gameFlow.at(i)->victoryPoints;
                }
            }
            if (gameFlow.at(currentPlayer)->victoryPoints >= 10){
                cout << "Congrats, " << gameFlow.at(currentPlayer)->getName() << ", you have won the game!"<<endl;
                break;
            }    
        }
        currentPlayer++;
    }
}
