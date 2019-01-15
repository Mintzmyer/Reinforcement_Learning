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

Policy defaultPolicy;

TEST_CASE( "Policy class: Testing default constructor" ) {

    int size = defaultPolicy.getBoardSize();

    for (int i=0; i<size; i++) {
        REQUIRE( defaultPolicy.updatePolicyMatrix(i, (float)(size-i)) == 0 );
        REQUIRE( defaultPolicy.getValueAtOption(i) == (float)(size-i) );
    }

    REQUIRE( defaultPolicy.updatePolicyMatrix(size, 0.0) == -1);
    REQUIRE( defaultPolicy.updatePolicyMatrix(-1, 0.0) == -1);

    for (int i=0; i<size; i++) {
        REQUIRE( defaultPolicy.getValueAtOption(i) == (float)(size-i) );
    }

    REQUIRE( defaultPolicy.getValueAtOption(size) == 0.0 );
    REQUIRE( defaultPolicy.getValueAtOption(-1) == 0.0 );

    for (int i=0; i<size; i++) {
        REQUIRE( defaultPolicy.updatePolicyMatrix(i, (float)(i)) == 0 );
        REQUIRE( defaultPolicy.getValueAtOption(i) == (float)9.0 );
    }

}


Policy aPolicy(16);

TEST_CASE( "Policy class: Testing parameterized constructor" ) {

    int size = aPolicy.getBoardSize();

    for (int i=0; i<size; i++) {
        REQUIRE( aPolicy.updatePolicyMatrix(i, (float)(size-i)) == 0 );
        REQUIRE( aPolicy.getValueAtOption(i) == (float)(size-i) );
    }

    REQUIRE( aPolicy.updatePolicyMatrix(size, 0.0) == -1);
    REQUIRE( aPolicy.updatePolicyMatrix(-1, 0.0) == -1);

    for (int i=0; i<size; i++) {
        REQUIRE( aPolicy.getValueAtOption(i) == (float)(size-i) );
    }

    REQUIRE( aPolicy.getValueAtOption(size) == 0.0 );
    REQUIRE( aPolicy.getValueAtOption(-1) == 0.0 );

    for (int i=0; i<size; i++) {
        REQUIRE( aPolicy.updatePolicyMatrix(i, (float)(i)) == 0 );
        REQUIRE( aPolicy.getValueAtOption(i) == (float)size );
    }

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
