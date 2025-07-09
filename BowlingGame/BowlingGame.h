
#pragma once  // Ensures this header is included only once during compilation

#include <vector>     // For using std::vector to store multiple frames
#include "Player.h"   // Include Player class definition
#include "Frame.h"    // Include Frame class definition

// BowlingGame class manages the game for a single player
class BowlingGame {
private:
    Player player;                  // Represents the player playing the game
    std::vector<Frame> frames;     // Stores up to 10 frames played by the player

public:
    // Constructor: Initializes the game with a player
    BowlingGame(Player player);

    // Adds a frame (one turn) to the game
    void addFrame(Frame frame);

    // Calculates and returns the total score of the game
    int calculateScore();
};
