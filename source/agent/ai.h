/*
 *
 *
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

    // Update the policy matrix with new reinforcement
    int updatePolicyMatrix(int option, float value);

    // Return the current policy matrix
    float* getPolicyMatrix();

    // Return the current value of the ith option of the policy matrix
    float getValueAtOption(int option);
};


class Ai {

  private:

    // Move score matrix: Total score for every move => [0, N) 
    // Policy* mScoresMatrix;
    std::map<int, Policy> mScoresMatrix;

    // Move tries matrix: Total tries for every move => [0, N)
    // Policy* mTriesMatrix;
    std::map<int, Policy> mTriesMatrix;

    // Total size of the modeled game matrix
    int mMatrixSize;

    // Size of the modeled game options per state
    int mBoardSize;

  public:

    // Constructor
    Ai(int matrixSize, int gameboardSize);

    // Function to fetch state score: Total score/Total games => [-1, 1]
    Policy getStateMatrix(int state);

    // Function to select a move: Greedy vs Random => [0, 1]
    int getMove(Policy stateMatrix, float exploration);

    // Function to calculate and distribute reward
    int rewardPolicy(int state, int move, float value);
};

#endif