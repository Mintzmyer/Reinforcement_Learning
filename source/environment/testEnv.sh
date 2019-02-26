#!/bin/bash

# Script to compile and run Catch unit tests
g++ -std=c++11 -Wall -I ../../catch2/ -c ../../catch2/mainTestCase.cpp
g++ -std=c++11 -c environment.cpp
g++ -std=c++11 -Wall -I ../../catch2/ -o envTestCases mainTestCase.o environment.o envTest.cpp && ./envTestCases --success

rm mainTestCase.o environment.o
