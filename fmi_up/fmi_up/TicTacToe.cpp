#include "TicTacToe.h"


void TicTacToe::TicTacToe(){
        cout << "Player count: "; cin >> this->playerCount;
        cout << "Field size (default is 3): "; cin >> this->size;
        if(this->size<3) this->size=3;
        this->field = new Matrix(this->size,this->size,true);
}

void TicTacToe::start(){
    char posX, posY;
    char hitCount=0;
    unsigned long playerIndex=1;

    do{
        this->crPlayer=playerIndex % this->playerCount;
        do{
            cout << "Player " << playerIndex % this->playerCount << " mark position: ";
            cin >> posX >> posY;
        } while(!this->field(posX, posY))         // do this while [x,y] cell isn't 0
        this->field(posX,posY)=this->crPlayer;          //mark player cell

        this->field->walk(WALK_ALL, [crPlayer](value, fgReset){
            hitCount = (!fgReset)*hitCount + value==crPlayer;
        });

        if(hitCount==size) this->winner=this->crPlayer;                         //Check for winner
        if(playerIndex>0xFFFFFFFF) playerIndex %= 0xFFFFFFFF;       //Fix index
        playerIndex++;
    } while(!this->winner);                                               //Loop while there isn't a winner
    cout << "Player #" << this->winner << " has won the game!";
}