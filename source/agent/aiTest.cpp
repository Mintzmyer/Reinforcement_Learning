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

TEST_CASE( "Policy class: Testing parameterized constructor" ) {

    Policy aPolicy(9);

    for (int i=0; i<9; i++) {
        REQUIRE( aPolicy.updatePolicyMatrix(i, (float)(9-i)) == 0 );
        REQUIRE( aPolicy.getValueAtOption(i) == (float)(9-i) );
    }

    REQUIRE( aPolicy.updatePolicyMatrix(9, 0.0) == -1);
    REQUIRE( aPolicy.updatePolicyMatrix(-1, 0.0) == -1);

    for (int i=0; i<9; i++) {
        REQUIRE( aPolicy.getValueAtOption(i) == (float)(9-i) );
    }

    REQUIRE( aPolicy.getValueAtOption(9) == 0.0 );
    REQUIRE( aPolicy.getValueAtOption(-1) == 0.0 );
}

