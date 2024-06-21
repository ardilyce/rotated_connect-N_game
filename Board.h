//
// Created by Ardil Yuce on 1.05.2024
// 32375
//

#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
using namespace std;

class Board{
private:
    char ** board;
    int target_length;
    int size;
    bool is_full();
    bool column_target(char piece);
    bool row_target(char piece);
    bool diagonal_target(char piece);

public:
    Board(int board_size, int length);
    ~Board();

    void print_board();
    bool put_piece(char piece, int column);
    void turn_board_clockwise();
    char get_game_status();

};

#endif //_BOARD_H