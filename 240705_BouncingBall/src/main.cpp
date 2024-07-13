#include "game.hpp"
#include <memory>


int main() {
    std::shared_ptr<olc::PixelGameEngine> game = std::make_shared<BouncingBalls>();

    if (game->Construct(640, 480, 2, 2)) { // Construct the game window
        game->Start(); // Start the game loop
    }

    return 0;
}
