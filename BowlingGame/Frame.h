#pragma once  // Ensures the header file is included only once during compilation

// Frame class represents a single frame in a bowling game
class Frame {
public:
    // Rolls in the frame
    int roll1, roll2, roll3;

    // Flags to indicate if the frame is a strike or a spare
    bool isStrike, isSpare;

    // Constructor: initializes rolls and flags
    Frame();

    // Sets the values for the first two rolls and identifies strike/spare
    void setRolls(int r1, int r2);

    // Sets all three rolls (used in the 10th frame which may have a bonus roll)
    void setTenthFrame(int r1, int r2, int r3);

    // Returns the total score of the frame (roll1 + roll2 + roll3)
    int getScore() const;

    // Returns the sum of the first two rolls
    int getFirstTwoRolls() const;

    // Returns the first roll only
    int getFirstRoll() const;
};
