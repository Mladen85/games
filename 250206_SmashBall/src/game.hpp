#ifndef __GAME_HPP__
#define __GAME_HPP__

//This game uses the olcPixelGameEngine by Javidx9.
#include "olcPixelGameEngine.h"
#include "ball.hpp"
#include <vector>

class BouncingBalls : public olc::PixelGameEngine {
public:
    BouncingBalls();

    bool OnUserCreate() override;

    bool OnUserUpdate(float fElapsedTime) override;

private:
    std::vector<Ball> balls;
};

#endif /* __GAME_HPP__ */