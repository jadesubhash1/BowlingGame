#include "BowlingGame.h"
#include <stdexcept>

BowlingGame::BowlingGame(Player p) : player(p) {}

void BowlingGame::addFrame(Frame frame) {
    if (frames.size() >= 10) throw std::runtime_error("Cannot add more than 10 frames");
    frames.push_back(frame);
}

int BowlingGame::calculateScore() {
    int total = 0;
    for (size_t i = 0; i < frames.size(); ++i) {
        Frame& f = frames[i];
        total += f.getFirstTwoRolls();

        if (f.isStrike && i + 1 < frames.size()) {
            total += frames[i + 1].getFirstTwoRolls();
        } else if (f.isSpare && i + 1 < frames.size()) {
            total += frames[i + 1].getFirstRoll();
        }
    }
    if (frames.size() == 10) total += frames[9].roll3;
    return total;
}