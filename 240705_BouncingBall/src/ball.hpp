#ifndef __BALL_HPP__
#define __BALL_HPP__

#include "olcPixelGameEngine.h"
#include "game.hpp"

class Ball {
public:
    Ball(olc::vf2d pos, olc::vf2d vel, float rad, olc::Pixel col);

    void Update(float fElapsedTime, const olc::vi2d& screenSize);

    void Draw(olc::PixelGameEngine* pge);

    bool IsCollidingWith(const Ball& other) const;

    void ResolveCollision(Ball& other);

//TODO: Define members as private and add required getters and setters
public:
    olc::vf2d position;
    olc::vf2d velocity;
    float radius;
    olc::Pixel color;
};

#endif /* __BALL_HPP__ */