#include <iostream>
#include "BowlingGame.h"

int main() {
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

    std::cout << "Final Score: " << game.calculateScore() << std::endl;
    return 0;
}