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

