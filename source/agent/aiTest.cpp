/* Test cases for Ai and Policy classes
 *
 *
 *
 */

// g++ -std=c++11 -Wall -o 010-TestCase 010-TestCase.cpp && ./010-TestCase --success
// g++ -std=c++11 -Wall -I ../catch/ -o 010-TestCase 010-TestCase.cpp && ./010-TestCase --success


// aiTest.cpp

// main() provided by Catch in file ../../catch2/mainTestCase.cpp.

#include "../../catch2/catch.hpp"
#include "ai.h"

// Tests the updatePolicyMatrix() and getValueAtOption()
//     functions for each valid index of the matrix
void updateAndGetValue(Policy anyPolicy, float newValue) {
    int size = anyPolicy.getBoardSize();

    for (int i=0; i<size; i++) {
        float startingValue = anyPolicy.getValueAtOption(i);
        REQUIRE( anyPolicy.updatePolicyMatrix(i, (float)(newValue-i)) == 0.0 );
        REQUIRE( anyPolicy.getValueAtOption(i) == (float)(newValue-i)+startingValue );
    }
}

// Tests some invalid indices near the matrix with functions
//     updatePolicyMatrix() and getValueAtOption()
void invalidUpdateAndGetValue(Policy anyPolicy, float newValue) {
    int size = anyPolicy.getBoardSize();
    int invalidBelow, invalidAbove;

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

/*
TEST_CASE( "Policy class: Return the current policy matrix") {
    int size = aPolicy.getBoardSize();
    float * aMatrix = aPolicy.getPolicyMatrix();
    for (int i = 0; i < size; i++) {
        REQUIRE( *(aMatrix+(i*(sizeof(float)))) == (float)size );
    }
}
*/
