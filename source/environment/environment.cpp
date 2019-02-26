/*
 *
 *
 *
 */

#include "environment.h"

// The move class encapsulates information about updating a board state

// Constructor
Move::Move(int oldPos, char oldPosValue, int newPos, char newPosValue) {
    mOldPos = oldPos;
    mOldPosValue = oldPosValue;
    mNewPos = newPos;
    mNewPosValue = newPosValue;
}

// Constructor
Move::Move(int newPos, char newPosValue) {
    mNewPos = newPos;
    mNewPosValue = newPosValue;
    mOldPos = NULL;
    mOldPosValue = NULL;
}

// Get updated position's and values
int Move::getOldPos() {
    return mOldPos;
}

char Move::getOldPosVal() {
    return mOldPosValue;
}

int Move::getNewPos() {
    return mNewPos;
}

char Move::getNewPosVal() {
    return mNewPosValue;
}



