#include "Frame.h"

Frame::Frame() : roll1(0), roll2(0), roll3(0), isStrike(false), isSpare(false) {}

void Frame::setRolls(int r1, int r2) {
    roll1 = r1;
    roll2 = r2;
    if (r1 == 10) isStrike = true;
    else if (r1 + r2 == 10) isSpare = true;
}

void Frame::setTenthFrame(int r1, int r2, int r3) {
    setRolls(r1, r2);
    roll3 = r3;
}

int Frame::getScore() const {
    return roll1 + roll2 + roll3;
}

int Frame::getFirstTwoRolls() const {
    return roll1 + roll2;
}

int Frame::getFirstRoll() const {
    return roll1;
}