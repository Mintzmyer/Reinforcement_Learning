/* Test cases for Ai and Policy classes
 *
 *
 *
 */


// aiTest.cpp

// main() provided by Catch in file ../../catch2/mainTestCase.cpp.

#include <stdlib.h>
#include <time.h>
#include "../../catch2/catch.hpp"
#include "ai.h"

// ----------------    Policy class    ----------------

// Tests the Policy::updatePolicyMatrix() and Policy::getValueAtOption()
//     functions for each valid index of the matrix
void updateAndGetValue(Policy anyPolicy, float newValue) {
    INFO(" Policy::updateAndGetValue test function: ");
    int size = anyPolicy.getBoardSize();

    // Verify the for-loop runs at least once, to avoid silent failures
    REQUIRE ( size > 0 );

    for (int i=0; i<size; i++) {
        float startingValue = anyPolicy.getValueAtOption(i);
        REQUIRE( anyPolicy.updatePolicyMatrix(i, (float)(newValue-i)) == 0.0 );
        REQUIRE( anyPolicy.getValueAtOption(i) == (float)(newValue-i)+startingValue );
    }
}

// Tests some invalid indices near the matrix with functions
//     Policy::updatePolicyMatrix() and Policy::getValueAtOption()
void invalidUpdateAndGetValue(Policy anyPolicy, float newValue) {
    INFO(" Policy::invalidUpdateAndGetValue test function: ");
    int size = anyPolicy.getBoardSize();
    int invalidBelow, invalidAbove;

    // Verify the for-loop runs at least once, to avoid silent failures
    REQUIRE ( size > 0 );

    for (int i=0; i<size; i++) {
        invalidBelow = ((-1)*i)-1;  // [0, size-1] > [-size, -1] below valid range
        invalidAbove = (i+size);    // [0, size-1] < [size, 2*size] above valid range

        // Returns 0.0 when index invalid
        REQUIRE( anyPolicy.getValueAtOption(invalidBelow) == (float)0.0 );
        REQUIRE( anyPolicy.getValueAtOption(invalidAbove) == (float)0.0 );

        // Returns -1.0 when update invalid
        REQUIRE( anyPolicy.updatePolicyMatrix(invalidBelow, (float)(newValue-i)) == (float)-1.0 );
        REQUIRE( anyPolicy.updatePolicyMatrix(invalidAbove, (float)(newValue-i)) == (float)-1.0 );

        // Returns 0.0 when index invalid
        REQUIRE( anyPolicy.getValueAtOption(invalidBelow) == (float)0.0 );
        REQUIRE( anyPolicy.getValueAtOption(invalidAbove) == (float)0.0 );
    }
}

// Tests the Policy::getPolicyMatrix() function, and verifies the
//     array matches values returned by Policy::getValueAtOption()
void verifyGetPolicyMatrix(Policy anyPolicy) {
    INFO(" Policy::verifyGetPolicyMatrix test function: ");
    int size = anyPolicy.getBoardSize();
    float ithValue, totValue;
    float * aMatrix = anyPolicy.getPolicyMatrix();

    // Verify the for-loop runs at least once, to avoid silent failures
    REQUIRE ( size > 0 );

    totValue = 0.0;
    for (int i = 0; i < size; i++) {
        ithValue = anyPolicy.getValueAtOption(i);
        REQUIRE( (float)*(aMatrix+(i)) == ithValue );
        totValue += ithValue;
    }

    if (totValue == 0.0) {
        WARN("ALERT: Total value is zero, could indicate matrix is uninitialized");
    }
}

Policy defaultPolicy;

TEST_CASE( "Policy class: Testing default constructor" ) {
    int size = defaultPolicy.getBoardSize();
    REQUIRE(size > 0);

    updateAndGetValue(defaultPolicy, 5.0);
    invalidUpdateAndGetValue(defaultPolicy, 4.0);

    updateAndGetValue(defaultPolicy, -3.14);
    invalidUpdateAndGetValue(defaultPolicy, -6.02);

}


Policy a16Policy(16);


TEST_CASE( "Policy class: Testing parameterized constructor" ) {

    updateAndGetValue(a16Policy, 5.0);
    invalidUpdateAndGetValue(a16Policy, 4.0);

    updateAndGetValue(a16Policy, -3.14);
    invalidUpdateAndGetValue(a16Policy, -6.02);

}


TEST_CASE( "Policy class: Return the current policy matrix with getPolicyMatrix()") {
    SECTION( " Default policy: Verify matrix values are accurate" ) {
        verifyGetPolicyMatrix(defaultPolicy);
    }
    SECTION( " Paramterized policy: Verify matrix values are accurate" ) {
        verifyGetPolicyMatrix(a16Policy);
    }
}

// ----------------    Ai class    ----------------


// Tests the Ai::updateReward() and Ai::getStateScore()
//     functions for a variety of board states
void updateAndGetScore(Ai anyAi, float newValue) {
    srand(time(NULL));
    INFO(" Ai::updateReward test function: ");
    int size = 64;

    // Verify the for-loop runs at least once, to avoid silent failures
    REQUIRE ( size > 0 );
    float startingScore, stateValue, stateTries;

    for (int i=0; i<size; i++) {
        int randState = rand() % 1000;

        // Randomly get -1, 0, or +1
        int randReward = rand() % 3 -1;
        startingScore = anyAi.getStateScore(randState);
        stateValue = anyAi.getStateValue(randState);
        stateTries = anyAi.getStateTries(randState);
        if (stateTries == 0.0 || stateValue == 0.0) {
            REQUIRE( startingScore == 0.0 );
        } else {
            REQUIRE( startingScore == stateValue/stateTries );
        }

        REQUIRE( anyAi.updateReward(randState, (float)randReward) == 0.0);

        stateValue = anyAi.getStateValue(randState);
        stateTries = anyAi.getStateTries(randState);
        
        REQUIRE( anyAi.getStateScore(randState) == (stateValue/stateTries) );
    }
}


Ai a9Ai(9);
Ai a16Ai(16);

TEST_CASE( "Ai class: Testing constructor" ) {
    


}
