#!/bin/bash
# This script compiles the project, and compiles the unit tests
#     with Catch, the unit test framework. It then runs the
#     unit tests and reports the results. It's ideal for a TDD
#     framework, changes can be commit immediately following success

g++ -std=c++11 -Wall -I ../../catch2/ -c ../../catch2/mainTestCase.cpp
g++ -std=c++11 -c ai.cpp
g++ -std=c++11 -Wall -I ../../catch2/ -o agentTestCases mainTestCase.o ai.o agentTest.cpp && ./agentTestCases --success

rm mainTestCase.o ai.o
