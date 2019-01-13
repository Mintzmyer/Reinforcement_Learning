#!/bin/bash

# Script to compile and run Catch unit tests
g++ -std=c++11 -Wall -I ../../catch2/ -c ../../catch2/mainTestCase.cpp
g++ -std=c++11 -c ai.cpp
g++ -std=c++11 -Wall -I ../../catch2/ -o aiTestCases mainTestCase.o ai.o aiTest.cpp && ./aiTestCases --success

rm mainTestCase.o ai.o
