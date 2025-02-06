#include "game.hpp"


int main() {
    BouncingBalls game;

    if (game.Construct(640, 480, 2, 2)) { // Construct the game window
        game.Start(); // Start the game loop
    }

    return 0;
}
