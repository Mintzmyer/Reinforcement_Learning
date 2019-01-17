/*
 * This source implements the Ai and Policy classes
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


#include "ai.h"


// The policy class encapsulating the policy matrices

// Default Constructor - overwrite this in child classes for other games
Policy::Policy()  {
    mPolicyMatrix = new float[9];
    mBoardSize = 9;
    for (int i = 0; i < mBoardSize; i++) {
        mPolicyMatrix[i] = (float)0.0;
    }
    //Policy(9);
}

// Parameterized constructor
Policy::Policy(int gameboardSize)  {
    mPolicyMatrix = new float[gameboardSize];
    mBoardSize = gameboardSize;
    for (int i = 0; i < mBoardSize; i++) {
        mPolicyMatrix[i] = (float)0.0;
    }
}

// Return mBoardSize
int Policy::getBoardSize() {
    return mBoardSize;
}

// Update the policy matrix with new reinforcement
int Policy::updatePolicyMatrix(int option, float value) {
    if ((0 <= option) && (option < mBoardSize)) {
        mPolicyMatrix[option] += value;
        return 0;
    } else {
        return -1;
    }
}

// Return the current policy matrix
float* Policy::getPolicyMatrix() {
    return mPolicyMatrix;
}

// Return the current value of the ith option of the policy matrix
float Policy::getValueAtOption(int option) {
    if ((0 <= option) && (option < mBoardSize)) {
        return mPolicyMatrix[option];
    } else {
        // To avoid throwing a null, return 0
        return 0.0;
    }
}


// The AI class encapsulating the AI logic and functionality

// Constructor
Ai::Ai(int totMatrixSize, int gameboardSize) {
    mMatrixSize = totMatrixSize;
    mBoardSize = gameboardSize;
}


// Function to fetch state score: Total score/Total games => [-1, 1]
Policy Ai::getStateMatrix(int state) {
    Policy nextMoveMatrix(mBoardSize);

    // Verify policy matrix already exists
    if (state < mMatrixSize) {
        float score, tries;

        for (int i=0; i < mBoardSize; i++){
            score = mScoresMatrix[state].getValueAtOption(i);
            tries = mTriesMatrix[state].getValueAtOption(i);
            if (tries == 0.0 || score == 0.0) {
                nextMoveMatrix.updatePolicyMatrix(i, (float) 0.0);
            } else {
                nextMoveMatrix.updatePolicyMatrix(i, (float)(score/tries) );
            }
        }
    } else {
        for (int i=0; i < mBoardSize; i++){
            nextMoveMatrix.updatePolicyMatrix(i, (float) 0.0);
        }
    }
    return nextMoveMatrix;
}

// Function to select a move: Random vs Greedy => [0, 1]
int Ai::getMove(Policy stateMatrix, float exploration) {
    return 0;
}

int Ai::rewardPolicy(int state, int move, float value) {
    if (state < mMatrixSize) {
        mScoresMatrix[state].updatePolicyMatrix(move, value);
        mTriesMatrix[state].updatePolicyMatrix(move, 1.0);
        return 0;
    } else {
        return -1;
    }
}


