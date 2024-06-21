//
// Created by Ardil Yuce on 1.05.2024
// 32375
//

#include "Board.h"

/******************************************/
            //CONSTRUCTORS

Board::Board(int board_size, int length)
{
    size = board_size; //set the board size
    board = new char*[size]; //allocate an array of char pointers
    target_length = length; //set the target length

    for (int i = 0; i < size; i++)
    {
        board[i] = new char[size]; //allocate an array of chars for each row
        for (int j = 0; j < size; j++)
        {
            board[i][j] = '-'; //initialize each cell with '-'
        }
    }
}

Board::~Board()
{
    for (int i = 0; i < size; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}

/******************************************/

/******************************************/
            //HELPER FUNCTIONS

bool Board::is_full()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == '-') //if there is a space, board is not full
            {
                return false;
            }
        }
    }
    return true;
}

bool Board::column_target(char piece)
{
    bool check = true; //this variable is added since using "break" statement is forbidden
    for (int i = 0; i < size; i++) //loop through each column
    {
        for (int j = size - 1; j >= target_length - 1; j--) //start from bottom, go up until there's enough room for target_length
        {
            check = true;
            int count = 0;
            for (int k = 0; k < target_length and check; k++) //check the sequence upwards
            {
                if (board[j - k][i] == piece) {count++;}
                else {check= false;}  //reset count if a different piece is encountered

                if (count == target_length) {return true;} //found target length of consecutive pieces
            }
        }
    }
    return false;  //no column met the criteria
}

bool Board::row_target(char piece)
{
    bool check = true; //this variable is added since using "break" statement is forbidden
    for (int j = size - 1; j >= 0; j--) //loop through each row starting from the bottom
    {
        for (int i = 0; i <= size - target_length; i++) //loop through starting positions in the row where a full target_length sequence can fit
        {
            check = true;
            int count = 0;
            for (int k = 0; k < target_length and check; k++) //check the sequence horizontally
            {
                if (board[j][i + k] == piece) {count++;}
                else {check = false;} //reset count if a different piece is encountered

                if (count == target_length) {return true;} //found target length of consecutive pieces
            }
        }
    }
    return false; //no row met the criteria
}

bool Board::diagonal_target(char piece) {
    bool check = true; //this variable is added since using "break" statement is forbidden

    //check diagonals from bottom-left to top-right
    //start from bottom row, iterate over all columns that can start a diagonal of the required length
    for (int startCol = 0; startCol <= size - target_length; startCol++)
    {
        for (int startRow = size - 1; startRow >= target_length - 1; startRow--)
        {
            check = true;
            int count = 0;
            for (int k = 0; k < target_length and check; k++)
            {
                if (board[startRow - k][startCol + k] == piece){count++;}
                else{check =false;}

                if (count == target_length) {return true;}
            }
        }
    }
    //check diagonals from top-left to bottom-right
    //start from top row, iterate over all columns that can start a diagonal of the required length
    for (int startCol = 0; startCol <= size - target_length; startCol++)
    {
        for (int startRow = 0; startRow <= size - target_length; startRow++)
        {
            check = true;
            int count = 0;
            for (int k = 0; k < target_length and check; k++)
            {
                if (board[startRow + k][startCol + k] == piece) {count++;}
                else {check = false;} //it breaks the for loop

                if (count == target_length) {return true;}
            }
        }
    }
    //consider diagonals starting from columns of the bottom row for top-right to bottom-left
    for (int startCol = 1; startCol <= size - target_length; startCol++)
    {
        for (int startRow = size - 1; startRow >= target_length - 1; startRow--)
        {
            check = true;
            int count = 0;
            for (int k = 0; k < target_length and check; k++)
            {
                if (board[startRow - k][startCol + k] == piece) {count++;}
                else {check = false;} //it breaks the for loop

                if (count == target_length) {return true;}
            }
        }
    }

    check = true;
    //consider diagonals starting from columns of the top row for bottom-left to top-right
    for (int startCol = 1; startCol <= size - target_length; startCol++)
    {
        for (int startRow = 0; startRow <= size - target_length; startRow++)
        {
            int count = 0;
            for (int k = 0; k < target_length and check; k++)
            {
                if (board[startRow + k][startCol - k] == piece){count++;}
                else {check = false;} //it breaks the for loop

                if (count == target_length) {return true;}
            }
        }
    }

    return false;  //no diagonal met the criteria
}

/******************************************/

/******************************************/
        //MEMBER FUNCTIONS (4)

void Board::print_board()
{
    cout << endl;
    for(int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool Board::put_piece(char piece, int column)
{
    if (is_full()) {return false;} //if it is full, no piece can be added

    if (0 <= column and column < size)
    {
        for (int i = size-1; i >= 0; i--) //iterates from bottom to top
        {
            if (board[i][column] == '-')
            {
                board[i][column] = piece;
                return true;
            }
        }
    }
    return false;
}

char Board::get_game_status()
{
    bool X_status = (column_target('X') or row_target('X') or diagonal_target('X')); //checking for whether X has target_length time consecutive term
    bool O_status = (column_target('O') or row_target('O') or diagonal_target('O')); //checking for whether O has target_length time consecutive term

    if ((X_status and O_status) or is_full()) {return 'D';} //if both of the pieces have enough pieces to win, or if it is full; it returns 'D' for draw
    else if (X_status) {return 'X';}
    else if(O_status) {return 'O';}
    else {return '-';} //if any of the conditions are not satisfied it continues the game
}

void Board::turn_board_clockwise()
{
    Board new_board(size, target_length);
    int count = 0;
    for (int i = size-1; i >= 0; i--) //variable for row index
    {
        for (int j = size-1; j >= 0; j--) //variable for column index
        {
            if(board[i][j] != '-')
            {
                new_board.put_piece(board[i][j],count);
            }
        }
        count++;
    }
    for (int i = 0; i < size; i++) //variable for row index
    {
        for (int j = 0; j < size; j++) //variable for column index
        {
            board[i][j] = new_board.board[i][j]; //initialize each cell
        }
    }
}

/******************************************/