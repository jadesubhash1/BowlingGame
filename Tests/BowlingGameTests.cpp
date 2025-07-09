#include <gtest/gtest.h>                           // Include Google Test framework
#include "../BowlingGame/Frame.h"                  // Include Frame class
#include "../BowlingGame/Player.h"                 // Include Player class
#include "../BowlingGame/BowlingGame.h"            // Include BowlingGame class

// ✅ Test Case: Spare bonus should add the next roll to the frame's score
TEST(ScoreCalculationTests, TestSpareBonus) {
    Player p("Test Player");                       // Create test player
    BowlingGame game(p);                           // Initialize game

    Frame f1; f1.setRolls(5, 5);                   // Spare (10 pins in 2 rolls)
    Frame f2; f2.setRolls(3, 2);                   // Next roll is 3 → bonus
    Frame f3; f3.setRolls(0, 0);                   // Empty frame

    game.addFrame(f1);
    game.addFrame(f2);
    game.addFrame(f3);

    // Frame 1: 10 + 3 = 13
    // Frame 2: 3 + 2 = 5
    // Frame 3: 0
    EXPECT_EQ(18, game.calculateScore());         // Verify total score
}

// ✅ Test Case: Strike bonus should add the next 2 rolls to the frame's score
TEST(ScoreCalculationTests, TestStrikeBonus) {
    Player p("Test Player");                       // Create test player
    BowlingGame game(p);                           // Initialize game

    Frame f1; f1.setRolls(10, 0);                  // Strike (10 pins in first roll)
    Frame f2; f2.setRolls(3, 4);                   // Next 2 rolls → 3 + 4 = 7 bonus
    Frame f3; f3.setRolls(0, 0);                   // Empty frame

    game.addFrame(f1);
    game.addFrame(f2);
    game.addFrame(f3);

    // Frame 1: 10 + 3 + 4 = 17
    // Frame 2: 3 + 4 = 7
    // Frame 3: 0
    EXPECT_EQ(24, game.calculateScore());         // Verify total score
}
