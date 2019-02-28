# Agent
This directory handles the logic associated with:
- Selecting new moves
- Storing statistical success of choices to improve predictions

###### Auto-Generated Documentation
### agentTest.cpp
 Test cases for Ai and Policy classes
  
  This file contains unit tests for the functionality
  implemented in the Ai and Policy classes
 
### ai.cpp

  This source implements the Ai and Policy classes
 
  The Ai class is a generic parent class for ai
  non-specific to games. It handles storing the
  options and updating their weight by rewards,
  and selecting a new move given a game state
 
  The Policy class is really just a helper for
  the Ai class, wrapping the concept of what
  the policy options should look like for a 
  given game state.
 
 
### ai.h

  This header defines the Ai and Policy classes
 
  The Ai class is a generic parent class for ai
  non-specific to games. It handles storing the
  options and updating their weight by rewards,
  and selecting a new move given a game state
 
  The Policy class is really just a helper for
  the Ai class, wrapping the concept of what
  the policy options should look like for a 
  given game state.
 
 
### testAgent.sh

 This script compiles the project, and compiles the unit tests
     with Catch, the unit test framework. It then runs the
     unit tests and reports the results. It's ideal for a TDD
     framework, changes can be commit immediately following success
