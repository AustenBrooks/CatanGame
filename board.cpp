#include "board.h"


string Tile::render(int i){
}
Tile::Tile(){
    player="            ";
    isOccupied=false;
    isUpgraded=false;
}
void Tile::buySettlement(string player){
    this->player=player;
    isOccupied=true;
}
void Tile::upgradeSettlement(){
    isUpgraded=true;
}
Forest::Forest(int num){
    number=num;
    tileType=0;
}
string Forest::render(int i){
    stringstream s;
    switch(i){
        case 0: return ".____________.";
        
        case 1: if(number<10){
                    s<<"|Forest     "<<number<<"|";
                    return s.str();
                }
                else{
                    s<< "|Forest    "<<number<<"|";
                    return s.str();
                }
        
        case 2: if(isOccupied && isUpgraded)
                    return "|  ________  |";
                else
                    return "|            |";
        case 3: if(isOccupied && isUpgraded)
                    return "| /        \\ |";
                else if(isOccupied)
                    return"|    /''\\    |";
                else
                    return "|            |";
        case 4: if(isOccupied && isUpgraded)
                    return "| |        | |";
                else if(isOccupied)
                    return"|   |____|   |";
                else
                    return"|            |";
        
        case 5: if(isOccupied && isUpgraded)
                    return "| '--------' |";
                else
                    return "|            |";
        case 6: return"|"+player+"|";
        case 7: return ".------------.";
    }
}
Hills::Hills(int num){
    number=num;
    tileType=1;
}
string Hills::render(int i){
    stringstream s;
    switch(i){
        case 0: return ".____________.";
        
        case 1: if(number<10){
                    s<<"|Hills      "<<number<<"|";
                    return s.str();
                }
                else{
                    s<< "|Hills     "<<number<<"|";
                    return s.str();
                }
        
        case 2: if(isOccupied && isUpgraded)
                    return "|  ________  |";
                else
                    return "|            |";
        case 3: if(isOccupied && isUpgraded)
                    return "| /        \\ |";
                else if(isOccupied)
                    return"|    /''\\    |";
                else
                    return "|            |";
        case 4: if(isOccupied && isUpgraded)
                    return "| |        | |";
                else if(isOccupied)
                    return"|   |____|   |";
                else
                    return"|            |";
        
        case 5: if(isOccupied && isUpgraded)
                    return "| '--------' |";
                else
                    return "|            |";
        case 6: return"|"+player+"|";
        case 7: return ".------------.";
    }
}
Field::Field(int num){
    number=num;
    tileType=2;
}
string Field::render(int i){
    stringstream s;
    switch(i){
        case 0: return ".____________.";
        
         case 1: if(number<10){
                    s<<"|Field      "<<number<<"|";
                    return s.str();
                }
                else{
                    s<< "|Field     "<<number<<"|";
                    return s.str();
                }
        
        case 2: if(isOccupied && isUpgraded)
                    return "|  ________  |";
                else
                    return "|            |";
        case 3: if(isOccupied && isUpgraded)
                    return "| /        \\ |";
                else if(isOccupied)
                    return"|    /''\\    |";
                else
                    return "|            |";
        case 4: if(isOccupied && isUpgraded)
                    return "| |        | |";
                else if(isOccupied)
                    return"|   |____|   |";
                else
                    return"|            |";
        
        case 5: if(isOccupied && isUpgraded)
                    return "| '--------' |";
                else
                    return "|            |";
        case 6: return"|"+player+"|";
        case 7: return ".------------.";
    }
}
Pasture::Pasture(int num){
    number=num;
    tileType=3;
}
string Pasture::render(int i){
    stringstream s;
    switch(i){
        case 0: return ".____________.";
        
         case 1: if(number<10){
                    s<<"|Pasture    "<<number<<"|";
                    return s.str();
                }
                else{
                    s<< "|Pasture   "<<number<<"|";
                    return s.str();
                }
        
        case 2: if(isOccupied && isUpgraded)
                    return "|  ________  |";
                else
                    return "|            |";
        case 3: if(isOccupied && isUpgraded)
                    return "| /        \\ |";
                else if(isOccupied)
                    return"|    /''\\    |";
                else
                    return "|            |";
        case 4: if(isOccupied && isUpgraded)
                    return "| |        | |";
                else if(isOccupied)
                    return"|   |____|   |";
                else
                    return"|            |";
        
        case 5: if(isOccupied && isUpgraded)
                    return "| '--------' |";
                else
                    return "|            |";
        case 6: return"|"+player+"|";
        case 7: return ".------------.";
    }
}
Mountain::Mountain(int num){
    number=num;
    tileType=4;
}
string Mountain::render(int i){
    stringstream s;
    switch(i){
        case 0: return ".____________.";
        
         case 1: if(number<10){
                    s<<"|Mountain   "<<number<<"|";
                    return s.str();
                }
                else{
                    s<< "|Mountain  "<<number<<"|";
                    return s.str();
                }
        
        case 2: if(isOccupied && isUpgraded)
                    return "|  ________  |";
                else
                    return "|            |";
        case 3: if(isOccupied && isUpgraded)
                    return "| /        \\ |";
                else if(isOccupied)
                    return"|    /''\\    |";
                else
                    return "|            |";
        case 4: if(isOccupied && isUpgraded)
                    return "| |        | |";
                else if(isOccupied)
                    return"|   |____|   |";
                else
                    return"|            |";
        
        case 5: if(isOccupied && isUpgraded)
                    return "| '--------' |";
                else
                    return "|            |";
        case 6: return"|"+player+"|";
        case 7: return ".------------.";
    }
}