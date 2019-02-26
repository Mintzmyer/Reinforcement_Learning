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

TEST_CASE( "Board class: Testing updateBoard() and getBoardStateAt()" ) {
    createAndUpdateBoard();
}



