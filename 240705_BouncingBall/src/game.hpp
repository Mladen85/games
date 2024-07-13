#ifndef __GAME_HPP__
#define __GAME_HPP__

//This game uses the olcPixelGameEngine by Javidx9.
#include "olcPixelGameEngine.h"
#include "ball.hpp"
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

class Ball;

class BouncingBalls : public olc::PixelGameEngine {
public:
    BouncingBalls();
    virtual ~BouncingBalls();

    bool OnUserCreate() override;

    bool OnUserUpdate(float fElapsedTime) override;

    bool OnUserDestroy() override;

private:
    std::vector<Ball> balls;
    std::vector<std::thread> threads;
    std::mutex mtx;
    std::condition_variable cv;
    bool updateFlag = false;
    bool exitFlag = false;
    float elapsedTime = 0.0f;
    olc::vi2d screenSize;
};

#endif /* __GAME_HPP__ */