
/*
 *
 * 
 *
 */

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <map>
#include <stddef.h>

// Representation of a move, no game-specific logic
class Move {

  private:

    // Bool value to track if Move has 4 (or 2) params, either 0 (false) or 1 (true)
    int m4Params;

    // Old position and value to update it to (ie now vacant)
    int mOldPos;
    char mOldPosValue;

    // New position and value to update it to (ie now occupied)
    int mNewPos;
    char mNewPosValue;

  public:

    // Constructor to move game piece from one location to another
    Move(int oldPos, char oldPosValue, int newPos, char newPosValue);

    // Constructor to set new game piece down
    Move(int newPos, char newPosValue);

    // Function to check if Move has 4 params (or 2 params)
    int is4Params();

    // Function to get old position
    int getOldPos();
    // Function to get old position's value
    char getOldPosVal();
    // Function to get new position
    int getNewPos();
    // Function to get new position's value
    char getNewPosVal();

};

// Representation of game board, no game-specific logic
class Board {

  private:

    // Map of board: int key is position, char value is piece(s)
    std::map<int, char> mBoardMap;

  public:

    // Function to update board state with new move
    int updateBoard(int position, char newValue);

    // Function to get state of a particular board position
    char getBoardStateAt(int position);

    // Function to get board state
    std::map<int, char> getBoardState();

};

// Handles game-specific logic like valid moves and win conditions
// Updates Board class using Move class
class Environment {

  private:

    // Game board
    Board mGameBoard;

    // Array of game history, for n players the (i%n - 1)th index is nth player's move
    Board* mGameState;

    // Function to check if move is valid
    int isMoveValid(Move checkMove);

    // Function to check for win condition
    int isGameOver();

  public:

    // Function to update board state with new move
    int setNextMove(Move newMove);

    // Function to print board state
    int printBoard();

    // Function to get all possible move options
    Move* getAllMoves();

    // Helper function to get Game board for testing
    Board getGameBoard();
};

#endif
