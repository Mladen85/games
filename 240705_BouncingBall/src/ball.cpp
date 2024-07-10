#include "ball.hpp"

Ball::Ball(olc::vf2d pos, olc::vf2d vel, float rad, olc::Pixel col):
    position(pos),
    velocity(vel),
    radius(rad),
    color(col)
{}

void Ball::Update(float fElapsedTime, const olc::vi2d& screenSize) {
    // Move the ball
    position += velocity * fElapsedTime;
    // Check for collision with screen edges
    if (position.x <= radius || position.x >= screenSize.x - radius) {
        velocity.x *= -1;
    }

    if (position.y <= radius || position.y >= screenSize.y - radius) {
        velocity.y *= -1;
    }
}

void Ball::Draw(olc::PixelGameEngine* pge) {
    pge->FillCircle(position, radius, color);
}

bool Ball::IsCollidingWith(const Ball& other) const {
    return (position - other.position).mag() <= (radius + other.radius);
}

void Ball::ResolveCollision(Ball& other) {
    // Simple elastic collision resolution
    olc::vf2d normal = (position - other.position).norm();
    olc::vf2d relativeVelocity = velocity - other.velocity;
    
    float speed = relativeVelocity.dot(normal);
    if (speed > 0) {
        return;
    }

    float impulse = 2 * speed / (radius + other.radius);
    velocity -= impulse * normal * other.radius;
    other.velocity += impulse * normal * radius;
}