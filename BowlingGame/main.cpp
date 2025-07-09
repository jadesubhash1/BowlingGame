#include <iostream>            
#include "BowlingGame.h"       // Include game logic
#include "Player.h"            // Include Player class
#include "Frame.h"             // Include Frame class
#include <limits>              // For input validation using numeric_limits

// Helper function to safely take valid input for a bowling roll
int getValidRoll(const std::string& prompt, int max = 10) {
    int roll;
    while (true) {
        std::cout << prompt;
        std::cin >> roll;

        // Handle non-numeric input
        if (std::cin.fail()) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
            std::cout << "❌ Invalid input. Please enter a number between 0 and " << max << ".\n";
            continue;
        }

        // Validate range (0–10)
        if (roll < 0 || roll > max) {
            std::cout << "❌ Invalid entry. Must be between 0 and " << max << ".\n";
            continue;
        }

        return roll; // Valid input
    }
}

// Manual game: user inputs name and rolls for each frame
void runManualGame() {
    std::string name;
    std::cout << "Enter player name: ";
    std::cin.ignore();               // To clear leftover newline
    std::getline(std::cin, name);   // Read full name

    // Create a Player object using the given name.
    // This stores the player's name and prepares to track their frames and scores.
    Player player(name);

    // Create a BowlingGame object for the specified player.
    // This sets up a new game instance that will manage scoring, 
    // frame progression, and apply rules like strikes/spares for this player.
    BowlingGame game(player);


    for (int i = 1; i <= 10; ++i) {
        int r1, r2 = 0, r3 = 0;     // Initialize rolls
        Frame frame;

        std::cout << "\n🎯 Frame " << i << std::endl;

        // Input first roll
        r1 = getValidRoll("Enter roll 1: ");

        if (i == 10) {
            // Special rules for 10th frame
            if (r1 == 10) {
                // Strike: allow bonus roll
                r3 = getValidRoll("Enter roll 3 (bonus): ");
                frame.setTenthFrame(r1, 0, r3);
            } else {
                // Input second roll
                r2 = getValidRoll("Enter roll 2: ");

                if (r1 + r2 == 10) {
                    // Spare: allow bonus roll
                    r3 = getValidRoll("Enter roll 3 (bonus): ");
                    frame.setTenthFrame(r1, r2, r3);
                } else if (r1 + r2 < 10) {
                    // Normal frame with no bonus
                    frame.setTenthFrame(r1, r2, 0);
                } else {
                    // Invalid total pins in 10th frame
                    std::cout << "❌ Invalid entry. Total pins in 10th frame cannot exceed 10 unless strike.\n";
                    --i; // retry this frame
                    continue;
                }
            }
        } else {
            // For frames 1–9
            if (r1 == 10) {
                // Strike
                frame.setRolls(r1, 0);
            } else {
                while (true) {
                    r2 = getValidRoll("Enter roll 2: ");
                    if (r1 + r2 > 10) {
                        std::cout << "❌ Invalid entry. Total pins in a frame cannot exceed 10.\n";
                        continue;
                    }
                    break;
                }
                frame.setRolls(r1, r2); // Normal frame
            }
        }

        game.addFrame(frame); // Add frame to the game
    }

    // Display final score
    std::cout << "\n Final score for " << name << ": " << game.calculateScore() << std::endl;
}

// Hardcoded game with sample rolls (for testing/demo)
void runHardcodedGame() {
    Player p("John");
    BowlingGame game(p);

    // Create and add 10 predefined frames
    Frame f1; f1.setRolls(1, 4);
    Frame f2; f2.setRolls(4, 5);
    Frame f3; f3.setRolls(6, 4);     // Spare
    Frame f4; f4.setRolls(5, 5);     // Spare
    Frame f5; f5.setRolls(10, 0);    // Strike
    Frame f6; f6.setRolls(0, 1);
    Frame f7; f7.setRolls(7, 3);     // Spare
    Frame f8; f8.setRolls(6, 4);     // Spare
    Frame f9; f9.setRolls(10, 0);    // Strike
    Frame f10; f10.setTenthFrame(2, 6, 0);  // No bonus

    // Add frames to the game
    game.addFrame(f1);
    game.addFrame(f2);
    game.addFrame(f3);
    game.addFrame(f4);
    game.addFrame(f5);
    game.addFrame(f6);
    game.addFrame(f7);
    game.addFrame(f8);
    game.addFrame(f9);
    game.addFrame(f10);

    // Display final score
    std::cout << "\nFinal score for " << p.name << ": " << game.calculateScore() << std::endl;
}

// Main function:
int main() {
    int choice;

    // Display menu
    std::cout << "🎳 Welcome to the Bowling Game!\n";
    std::cout << "1. Play manually\n";
    std::cout << "2. Run hardcoded test\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;
    std::cin.ignore(); // flush newline from input

    // Based on user choice
    if (choice == 1) {
        runManualGame();  // Play with user input
    } else if (choice == 2) {
        runHardcodedGame();  // Run predefined test
    } else {
        std::cout << "Invalid choice. Exiting.\n";
    }

    return 0;
}
