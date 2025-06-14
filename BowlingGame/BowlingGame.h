#pragma once
#include <vector>
#include "Player.h"
#include "Frame.h"

class BowlingGame {
private:
    Player player;
    std::vector<Frame> frames;
public:
    BowlingGame(Player player);
    void addFrame(Frame frame);
    int calculateScore();
};