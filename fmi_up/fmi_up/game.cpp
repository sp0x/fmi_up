#include "Matrix.h"


void game(){
    int size=3;
    Matrix field(size,size,true);
    bool playerCount;
    bool winner = 0;
    unsigned long playerIndex=1;
    char crPlayer=1;
    char posX, posY;
    char hitCount;

    cout << "Player count: "; cin >> playerCount;

    do{
        crPlayer=playerIndex % playerCount;
        do{
            cout << "Player " << playerIndex % playerCount << " mark position: ";
            cin >> posX >> posY;
        } while(!field(posX, posY))         // do this while [x,y] cell isn't 0
        field(posX,posY)=crPlayer;          //mark player cell

        field.walk(WALK_ALL, [crPlayer](value, fgReset){
            if(fgReset){        hitCount=0;                     }
            else {              hitCount+= value==crPlayer;     }
        });

        if(hitCount==size) winner=crPlayer;                         //Check for winner
        if(playerIndex>0xFFFFFFFF) playerIndex %= 0xFFFFFFFF;       //Fix index
        playerIndex++;
    } while(!winner);

}