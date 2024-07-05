//This game uses the olcPixelGameEngine by Javidx9.
#include "game.hpp"

MyGame::MyGame() {
    // Constructor logic if needed
}

bool MyGame::OnUserCreate() {
    // Called once at the start, used for initialization
    return true;
}

bool MyGame::OnUserUpdate(float fElapsedTime) {
    // Called once per frame, where game logic and rendering occurs
    Clear(olc::BLACK); // Example: Clear screen with black color
    // Your game logic here
    return true;
}
