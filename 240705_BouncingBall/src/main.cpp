#include "game.hpp"


int main() {
    MyGame game;

    if (game.Construct(640, 480, 2, 2)) { // Example: Construct the game window
        game.Start(); // Start the game loop
    }

    return 0;
}
