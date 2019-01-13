/*
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

TEST_CASE( "Policy class: Testing constructor" ) {
    Policy aPolicy(9);
    REQUIRE( aPolicy.updatePolicyMatrix(2, 0.0) == 0);
}

