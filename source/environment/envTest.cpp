/* Test cases for Move, Board and Environment classes
 *
 *
 *
 */


// envTest.cpp

// main() provided by Catch in file ../../catch2/mainTestCase.cpp.

#include <stdlib.h>
#include <time.h>
#include "../../catch2/catch.hpp"
#include "environment.h"

// ----------------    Move class    ----------------

// Tests the Move constructor and getter functions

Move getRandMove4Param() {
    int oldPos, newPos;
    char oldPosVal, newPosVal;

    oldPos = rand() % 1000;
    newPos = rand() % 1000;
    // Randomly get any symbol, a-z, A-Z, punctuation etc
    oldPosVal = '!' + rand()%94;
    newPosVal = '!' + rand()%94;

    Move rMove(newPos, newPosVal);
    return rMove;
}

Move getRandMove2Param() {
    int newPos;
    char newPosVal;

    newPos = rand() % 1000;
    // Randomly get any symbol, a-z, A-Z, punctuation etc
    newPosVal = '!' + rand()%94;

    Move rMove(newPos, newPosVal);
    return rMove;
}



void createAndCheckValue() {
    INFO(" Move test function:");
    srand(time(NULL));

    int size = 64;
    int oldPos, newPos;
    char oldPosVal, newPosVal;

    // Verify the for-loop runs at least once, to avoid silent failures
    REQUIRE ( size > 0 );

    for (int i=0; i<size; i++) {
        oldPos = rand() % 1000;
        newPos = rand() % 1000;
        // Randomly get any symbol, a-z, A-Z, punctuation etc
        oldPosVal = '!' + rand()%94;
        newPosVal = '!' + rand()%94;

        Move aMove(oldPos, oldPosVal, newPos, newPosVal);

        // Verify the values match the getter function returns
        REQUIRE ( aMove.is4Params() == 1 );
        REQUIRE ( aMove.getOldPos() == oldPos );
        REQUIRE ( aMove.getOldPosVal() == oldPosVal );
        REQUIRE ( aMove.getNewPos() == newPos );
        REQUIRE ( aMove.getNewPosVal() == newPosVal );
    }

    for (int i=0; i<size; i++) {
        newPos = rand() % 1000;
        // Randomly get any symbol, a-z, A-Z, punctuation etc
        newPosVal = '!' + rand()%94;

        Move aMove(newPos, newPosVal);

        // Verify the values match the getter function returns
        REQUIRE ( aMove.is4Params() == 0 );
        REQUIRE ( aMove.getOldPos() == NULL );
        REQUIRE ( aMove.getOldPosVal() == NULL );
        REQUIRE ( aMove.getNewPos() == newPos );
        REQUIRE ( aMove.getNewPosVal() == newPosVal );
    }
}

TEST_CASE( "Move class: Testing all constructors" ) {
    createAndCheckValue();
}


// ----------------    Board class    ----------------

void createAndUpdateBoard() {
    INFO(" Board test function:");

    int size = 64;

    // Verify the for-loop runs at least once, to avoid silent failures
    REQUIRE ( size > 0 );

    Board aBoard;

    for (int i=0; i<size; i++) {
        Move aMove = getRandMove2Param();
        REQUIRE ( aBoard.updateBoard(aMove.getNewPos(), aMove.getNewPosVal()) == 0 );
        REQUIRE ( aBoard.getBoardStateAt(aMove.getNewPos()) == aMove.getNewPosVal() );
    }
}

void populateAndGetBoardState() {
    INFO(" Test function for getBoardState() ");

    int size = 188;

    // Verify the for-loop runs at least once, to avoid silent failures
    REQUIRE ( size > 0 );

    Board aBoard;
    char value;

    // Fill the game board with predictable content
    for (int i=0; i<size; i++) {
        value = '!' + i%94;
        aBoard.updateBoard(i, value);
    }

    std::map<int, char> boardState = aBoard.getBoardState();

    // Verify game board matches content
    for (int i=0; i<size; i++) {
        value = '!' + i%94;
        REQUIRE ( boardState[i] == value );
    }
    

}

TEST_CASE( "Board class: Testing updateBoard() and getBoardStateAt()" ) {
    createAndUpdateBoard();
}

TEST_CASE( "Board class: Testing getBoardState()" ) {
    populateAndGetBoardState();
}


// ----------------    Environment class    ----------------

void setMoveViaEnvironment() {
    INFO(" Test function for Environment::setNextMove() ");

    int size = 64;

    // Verify the for-loop runs at least once, to avoid silent failures
    REQUIRE ( size > 0 );

    Environment aEnvironment;
    Board aBoard;

    for (int i = 0; i<size; i++) {
        Move aMove = getRandMove4Param();
        REQUIRE( aEnvironment.setNextMove(aMove) == 0 );
        aBoard = aEnvironment.getGameBoard();
        REQUIRE( aBoard.getBoardStateAt(aMove.getOldPos()) == aMove.getOldPosVal() );
        REQUIRE( aBoard.getBoardStateAt(aMove.getNewPos()) == aMove.getNewPosVal() );
    }

    for (int i = 0; i<size; i++) {
        Move aMove = getRandMove2Param();
        REQUIRE( aEnvironment.setNextMove(aMove) == 0 );
        aBoard = aEnvironment.getGameBoard();
        REQUIRE( aBoard.getBoardStateAt(aMove.getNewPos()) == aMove.getNewPosVal() );

    }
}


TEST_CASE( "Environment class: Testing setNextMove() " ) {
    setMoveViaEnvironment();
}

void checkEndGameState() {
    INFO(" Verify generic Environment's isGameOver() returns -2 ")
    // This is a bit contrived, so I'll be brief
    // Testing this fn is much much more relevant
    // when overwritten for a specific game

    Board someBoard;
    Environment someEnvironment;

    REQUIRE( someEnvironment.isGameOver() == -2 );
    REQUIRE( someEnvironment.isGameOver(someBoard) == -2 );
}

TEST_CASE( "Environment class: Testing isGameOver() ") {
    checkEndGameState();
}
