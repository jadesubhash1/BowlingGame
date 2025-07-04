#include <iostream>
#include "BowlingGame.h"
#include "Player.h"
#include "Frame.h"
#include <limits> // For std::numeric_limits

int getValidRoll(const std::string& prompt, int max = 10) {
    int roll;
    while (true) {
        std::cout << prompt;
        std::cin >> roll;

        if (std::cin.fail()) {
            std::cin.clear(); // clear failbit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "❌ Invalid input. Please enter a number between 0 and " << max << ".\n";
            continue;
        }

        if (roll < 0 || roll > max) {
            std::cout << "❌ Invalid entry. Must be between 0 and " << max << ".\n";
            continue;
        }

        return roll;
    }
}

void runManualGame() {
    std::string name;
    std::cout << "Enter player name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    Player player(name);
    BowlingGame game(player);

    for (int i = 1; i <= 10; ++i) {
        int r1, r2 = 0, r3 = 0;
        Frame frame;

        std::cout << "\n🎯 Frame " << i << std::endl;

        r1 = getValidRoll("Enter roll 1: ");

        if (i == 10) {
            if (r1 == 10) {
                // Custom rule: Directly ask for 1 bonus roll (r3)
                r3 = getValidRoll("Enter roll 3 (bonus): ");
                frame.setTenthFrame(r1, 0, r3);  // Note: r2 = 0
            } else {
                r2 = getValidRoll("Enter roll 2: ");
                if (r1 + r2 == 10) {
                    r3 = getValidRoll("Enter roll 3 (bonus): ");
                    frame.setTenthFrame(r1, r2, r3);
                } else if (r1 + r2 < 10) {
                    frame.setTenthFrame(r1, r2, 0);
                } else {
                    std::cout << "❌ Invalid entry. Total pins in 10th frame cannot exceed 10 unless strike.\n";
                    --i; // repeat this frame
                    continue;
                }
            }
        } else {
            if (r1 == 10) {
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
                frame.setRolls(r1, r2);
            }
        }

        game.addFrame(frame);
    }

    std::cout << "\n✅ Final score for " << name << ": " << game.calculateScore() << std::endl;
}

void runHardcodedGame() {
    Player p("John");
    BowlingGame game(p);

    Frame f1; f1.setRolls(1, 4);
    Frame f2; f2.setRolls(4, 5);
    Frame f3; f3.setRolls(6, 4);
    Frame f4; f4.setRolls(5, 5);
    Frame f5; f5.setRolls(10, 0);
    Frame f6; f6.setRolls(0, 1);
    Frame f7; f7.setRolls(7, 3);
    Frame f8; f8.setRolls(6, 4);
    Frame f9; f9.setRolls(10, 0);
    Frame f10; f10.setTenthFrame(2, 6, 0);

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

    std::cout << "\nFinal score for " << p.name << ": " << game.calculateScore() << std::endl;
}

int main() {
    int choice;
    std::cout << "🎳 Welcome to the Bowling Game!\n";
    std::cout << "1. Play manually\n";
    std::cout << "2. Run hardcoded test\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;
    std::cin.ignore(); // flush newline

    if (choice == 1) {
        runManualGame();
    } else if (choice == 2) {
        runHardcodedGame();
    } else {
        std::cout << "Invalid choice. Exiting.\n";
    }

    return 0;
}
