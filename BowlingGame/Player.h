#pragma once  // Ensures this header is included only once during compilation

#include <string>  // Required for using std::string

// Player class represents a player in the bowling game
class Player {
public:
    std::string name;  // Stores the name of the player

    // Constructor: initializes the player with a given name
    Player(std::string name);
};
