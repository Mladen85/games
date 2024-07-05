//This game uses the olcPixelGameEngine by Javidx9.
#include "olcPixelGameEngine.h"

class MyGame : public olc::PixelGameEngine {
public:
    MyGame();

    bool OnUserCreate() override;

    bool OnUserUpdate(float fElapsedTime) override;
};
