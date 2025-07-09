
#include "BowlingGame.h"    // Include header file containing class definitions
#include <stdexcept>        // For throwing runtime errors

// Constructor: Initializes the BowlingGame with a given player
BowlingGame::BowlingGame(Player p) : player(p) {}

// Adds a frame to the game
void BowlingGame::addFrame(Frame frame) {
    // Ensure we don't add more than 10 frames (standard bowling rules)
    if (frames.size() >= 10) throw std::runtime_error("Cannot add more than 10 frames");
    
    // Add the frame to the list of frames
    frames.push_back(frame);
}

// Calculates the total score for the game
int BowlingGame::calculateScore() {
    int total = 0; // Total score accumulator

    // Loop through all frames
    for (size_t i = 0; i < frames.size(); ++i) {
        Frame& f = frames[i]; // Current frame

        // Add score of first two rolls in the frame (normal score)
        total += f.getFirstTwoRolls();

        // If the current frame is a strike
        // add the score of the next frame’s first two rolls as bonus
        if (f.isStrike && i + 1 < frames.size()) {
            total += frames[i + 1].getFirstTwoRolls();
        } 
        // If the current frame is a spare
        // add the score of the next frame’s first roll as bonus
        else if (f.isSpare && i + 1 < frames.size()) {
            total += frames[i + 1].getFirstRoll();
        }
    }

    // If it's the 10th frame, include the 3rd bonus roll (if any)
    if (frames.size() == 10) total += frames[9].roll3;

    return total; // Return final calculated score
}
