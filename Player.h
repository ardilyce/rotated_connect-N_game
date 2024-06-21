//
// Created by Ardil Yuce on 1.05.2024
// 32375
//

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include "Board.h"
using namespace std;

class Player{
private:
    Board & board;
    char piece;
public:
    Player(Board &board1, char symbol);

    bool put(int column);
    void turn_board();
    bool is_winner();
    char get_symbol();
};

#endif //_PLAYER_H
