#include <gtest/gtest.h>
#include "../BowlingGame/Frame.h"
#include "../BowlingGame/Player.h"
#include "../BowlingGame/BowlingGame.h"

TEST(ScoreCalculationTests, TestSpareBonus) {
    Player p("Test Player");
    BowlingGame game(p);

    Frame f1; f1.setRolls(5, 5); // Spare
    Frame f2; f2.setRolls(3, 2);
    Frame f3; f3.setRolls(0, 0);

    game.addFrame(f1);
    game.addFrame(f2);
    game.addFrame(f3);

    EXPECT_EQ(18, game.calculateScore());
}

TEST(ScoreCalculationTests, TestStrikeBonus) {
    Player p("Test Player");
    BowlingGame game(p);

    Frame f1; f1.setRolls(10, 0); // Strike
    Frame f2; f2.setRolls(3, 4);
    Frame f3; f3.setRolls(0, 0);

    game.addFrame(f1);
    game.addFrame(f2);
    game.addFrame(f3);

    EXPECT_EQ(24, game.calculateScore());
}
