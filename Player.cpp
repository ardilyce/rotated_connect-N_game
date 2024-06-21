//
// Created by Ardıl Yüce on 1.05.2024
// 32375
//

#include "Player.h"
#include "Board.h"

/******************************************/
            //CONSTRUCTORS

Player::Player(Board &board1, char symbol) : board(board1)
{
    piece = symbol;
}

/******************************************/

/******************************************/
            //MEMBER FUNCTIONS (4)

bool Player::put(int column)
{
    return (board.put_piece(piece, column));
}

void Player::turn_board()
{
    board.turn_board_clockwise();
}

bool Player::is_winner()
{
    char result = board.get_game_status();
    if (result == piece) {return true;}
    return false;
}

char Player::get_symbol()
{
    return piece;
}

/******************************************/
