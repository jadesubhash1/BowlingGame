#pragma once
class Frame {
public:
    int roll1, roll2, roll3;
    bool isStrike, isSpare;

    Frame();
    void setRolls(int r1, int r2);
    void setTenthFrame(int r1, int r2, int r3);
    int getScore() const;
    int getFirstTwoRolls() const;
    int getFirstRoll() const;
};