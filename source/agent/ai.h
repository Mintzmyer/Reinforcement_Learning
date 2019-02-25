/*
 * This header defines the Ai and Policy classes
 *
 * The Ai class is a generic parent class for ai
 * non-specific to games. It handles storing the
 * options and updating their weight by rewards,
 * and selecting a new move given a game state
 *
 * The Policy class is really just a helper for
 * the Ai class, wrapping the concept of what
 * the policy options should look like for a 
 * given game state.
 *
 */

#ifndef AI_H
#define AI_H

#include <map>

class Policy {

  private:

    // Matrix of policy values for a state
    float* mPolicyMatrix;

    // Size of modeled gameboard
    int mBoardSize;

  public:

    // Constructor
    Policy();
    Policy(int gameboardSize);

    // Get private member variable mBoardSize
    int getBoardSize();

    // Update the policy matrix with new reinforcement
    int updatePolicyMatrix(int option, float value);

    // Return the current policy matrix
    float* getPolicyMatrix();

    // Return the current value of the ith option of the policy matrix
    float getValueAtOption(int option);
};


class Ai {

  private:

    // State score matrix: Total score for every state => [0, N) 
    std::map<int, float> mScoresMatrix;

    // State tries matrix: Total tries for every state => [0, N)
    std::map<int, float> mTriesMatrix;

    // Total size of the modeled game matrix
    int mMatrixSize;

    // Size of the modeled game options per state
    int mBoardSize;

  public:

    // Constructor
    Ai(int gameboardSize);

    // TEST function to fetch value of state
    float getStateValue(int state);

    // TEST function to fetch value of tries
    float getStateTries(int state);

    // Function to fetch state score: Total score/Total games => [-1, 1]
    float getStateScore(int state);

    // Function to select a move: Greedy vs Random => [0, 1]
    int getMove(Policy stateMatrix, float exploration);

    // Function to calculate and distribute reward
    int updateReward(int state, float value);
};

#endif
