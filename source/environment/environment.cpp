/*
 *
 *
 *
 */

#include "environment.h"

// The Move class encapsulates information about updating a board state

// Constructor
Move::Move(int oldPos, char oldPosValue, int newPos, char newPosValue) {
    mOldPos = oldPos;
    mOldPosValue = oldPosValue;
    mNewPos = newPos;
    mNewPosValue = newPosValue;
    m4Params = 1;
}

// Constructor
Move::Move(int newPos, char newPosValue) {
    mNewPos = newPos;
    mNewPosValue = newPosValue;
    mOldPos = NULL;
    mOldPosValue = NULL;
    m4Params = 0;
}

// Get updated position's and values
int Move::getOldPos() {
    return mOldPos;
}

char Move::getOldPosVal() {
    return mOldPosValue;
}

int Move::getNewPos() {
    return mNewPos;
}

char Move::getNewPosVal() {
    return mNewPosValue;
}

int Move::is4Params() {
    return m4Params;
}

// The Board class encapsulates information about the board state, pieces etc

// Function to update board state with new move
int Board::updateBoard(int position, char newValue) {
    mBoardMap[position] = newValue;
    return 0;
}

// Function to get state of a particular board position
char Board::getBoardStateAt(int position) {
    return mBoardMap[position];
}

// Funtion to get complete board state
std::map<int, char> Board::getBoardState() {
    return mBoardMap;
}


// The Environment class encapsulates all the logic for updating a game


// Function to check if move is valid
// This is all game-specific logic and will need
//     to be re-defined per game
int Environment::isMoveValid(Move checkMove) {
    return 1; // For now, just return true
}

// Helper function to get Game board for testing
Board Environment::getGameBoard() {
    return mGameBoard;
}

// Function to update board state with new move
int Environment::setNextMove(Move newMove) {
    if (isMoveValid(newMove)) {
        int result;
        if (newMove.is4Params()) {
            result = mGameBoard.updateBoard(newMove.getOldPos(), newMove.getOldPosVal());
        }
        result += mGameBoard.updateBoard(newMove.getNewPos(), newMove.getNewPosVal());
        return result;
    } else {
         return -1; // Error, invalid move
    }
}


