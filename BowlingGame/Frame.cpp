#include "Frame.h"  // Include the corresponding header for Frame class

// Default constructor: initializes rolls to 0 and flags to false
Frame::Frame() : roll1(0), roll2(0), roll3(0), isStrike(false), isSpare(false) {}

// Sets the values for the first two rolls in a frame
void Frame::setRolls(int r1, int r2) {
    roll1 = r1;
    roll2 = r2;

    // Check if it's a strike (all 10 pins in first roll)
    if (r1 == 10) 
        isStrike = true;
    
    // Check if it's a spare (total of 10 pins in two rolls)
    else if (r1 + r2 == 10) 
        isSpare = true;
}

// Sets all three rolls for the 10th frame (which may include a bonus roll)
void Frame::setTenthFrame(int r1, int r2, int r3) {
    setRolls(r1, r2); // Reuse logic for first two rolls
    roll3 = r3;       // Set the bonus third roll
}

// Returns the total score of this frame (all rolls included)
int Frame::getScore() const {
    return roll1 + roll2 + roll3;
}

// Returns the sum of the first two rolls (used in scoring logic)
int Frame::getFirstTwoRolls() const {
    return roll1 + roll2;
}

// Returns only the first roll's value (used for spare bonus logic)
int Frame::getFirstRoll() const {
    return roll1;
}
