#ifndef __BALL_HPP__
#define __BALL_HPP__

#include "olcPixelGameEngine.h"

struct Ball {
    olc::vf2d position;
    olc::vf2d velocity;
    float radius;
    olc::Pixel color;
};

#endif /* __BALL_HPP__ */