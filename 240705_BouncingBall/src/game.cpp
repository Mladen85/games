//This game uses the olcPixelGameEngine by Javidx9.
#include "game.hpp"

BouncingBalls::BouncingBalls() {
    sAppName = "Bouncing Balls";
}

bool BouncingBalls::OnUserCreate() {
    // Initialize balls with different positions, velocities, and colors
    balls.emplace_back(olc::vf2d(30, 30), olc::vf2d(50, 80), 25.0f, olc::RED);
    balls.emplace_back(olc::vf2d(100, 100), olc::vf2d(-60, 40), 25.0f, olc::BLUE);
    return true;
}

bool BouncingBalls::OnUserUpdate(float fElapsedTime) {
    Clear(olc::BLACK);

    // Update and draw balls
    for (auto& ball : balls) {
        ball.Update(fElapsedTime, olc::vi2d(ScreenWidth(), ScreenHeight()));
        ball.Draw(this);
    }

    // Check for collisions and resolve them
    for (size_t i = 0; i < balls.size(); ++i) {
        for (size_t j = i + 1; j < balls.size(); ++j) {
            if (balls[i].IsCollidingWith(balls[j])) {
                balls[i].ResolveCollision(balls[j]);
            }
        }
    }

    return true;
}
