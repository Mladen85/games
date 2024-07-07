//This game uses the olcPixelGameEngine by Javidx9.
#include "game.hpp"

BouncingBalls::BouncingBalls() {
    sAppName = "Bouncing Balls";
}

bool BouncingBalls::OnUserCreate() {
    // Initialize balls
    balls.push_back({ {50.0f, 50.0f}, {60.0f, 40.0f}, 10.0f, olc::RED });
    balls.push_back({ {150.0f, 100.0f}, {-60.0f, -40.0f}, 10.0f, olc::BLUE });
    return true;
}

bool BouncingBalls::OnUserUpdate(float fElapsedTime) {
    Clear(olc::BLACK);

    //Update balls
    for(auto& ball : balls) {
        //Update position
        ball.position += ball.velocity * fElapsedTime;

        // Check for collision with walls
        if (ball.position.x < ball.radius || ball.position.x > ScreenWidth() - ball.radius) {
            ball.velocity.x *= -1;
        }
        if (ball.position.y < ball.radius || ball.position.y > ScreenHeight() - ball.radius) {
            ball.velocity.y *= -1;
        }
    }

    // Check for collision between balls
    if ((balls[0].position - balls[1].position).mag2() < (balls[0].radius + balls[1].radius) * (balls[0].radius + balls[1].radius)) {
        // Simple elastic collision response
        olc::vf2d normal = (balls[1].position - balls[0].position).norm();
        olc::vf2d relativeVelocity = balls[0].velocity - balls[1].velocity;

        balls[0].velocity -= normal * (relativeVelocity.dot(normal));
        balls[1].velocity += normal * (relativeVelocity.dot(normal));
    }

    // Draw balls
    for (const auto& ball : balls) {
        FillCircle(ball.position, ball.radius, ball.color);
    }
    
    return true;
}
