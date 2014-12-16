#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE
#include "Matrix.h"
#include <iostream>
#include "stdio.h"

using namespace std;


class TicTacToe{
private:
    char size;
    char playerCount;
    char crPlayer;
    char winner;
    Matrix* field;
public:
    TicTacToe();
    void start();

};



#endif