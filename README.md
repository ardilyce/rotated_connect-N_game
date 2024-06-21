# Rotated Connect-N Game

## Overview

This project is an implementation of a modified Connect Four game, called Rotated Connect-N. The game is implemented in C++ and involves object-oriented principles, specifically focusing on object sharing concepts.

## Game Description

The game is a two-player game where players take turns to either place a piece on the board or rotate the board 90 degrees clockwise. The objective is to form a line of N consecutive pieces either horizontally, vertically, or diagonally.

## Files

- `Board.h`: Header file for the Board class.
- `Board.cpp`: Implementation file for the Board class.
- `Player.h`: Header file for the Player class.
- `Player.cpp`: Implementation file for the Player class.
- `main.cpp`: Main file that includes the game implementation and usage of the classes.

## Classes

### Board Class

The `Board` class is responsible for managing the game board. It includes the following functionalities:
- **Constructor**: Initializes the board with a given size and necessary length to win.
- **Destructor**: Deallocates the dynamic memory used by the board.
- **print_board()**: Displays the current state of the board.
- **put_piece(char piece, int column)**: Adds a game piece to a specified column.
- **turn_board_clockwise()**: Rotates the board 90 degrees clockwise.
- **get_game_status()**: Checks the game status to determine if there's a winner, a draw, or if the game is still ongoing.

### Player Class

The `Player` class manages the players and their actions. It includes the following functionalities:
- **Constructor**: Initializes the player with a reference to the shared Board object and the player's game piece.
- **put(int column)**: Places a piece in the specified column using the Board's `put_piece` function.
- **turn_board()**: Rotates the board using the Board's `turn_board_clockwise` function.
- **is_winner()**: Checks if the player has won the game using the Board's `get_game_status` function.
- **get_symbol()**: Returns the player's game piece character.

## Usage

To run the game, compile the provided files and execute the main program. The game will prompt for board size and the length of the line needed to win. Players will then take turns to either place a piece or rotate the board until one of them wins or the game ends in a draw.
