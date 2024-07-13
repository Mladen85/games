//This game uses the olcPixelGameEngine by Javidx9.
#include "game.hpp"



BouncingBalls::BouncingBalls() {
    sAppName = "Bouncing Balls";
}

BouncingBalls::~BouncingBalls() {
//     {
//         std::lock_guard<std::mutex> lock(mtx);
//         exitFlag = true;
//     }
//     cv.notify_all();
//     for (auto& t : threads) {
//         if (t.joinable())
//             t.join();
//     }
}

bool BouncingBalls::OnUserCreate() {
    screenSize = olc::vi2d(ScreenWidth(), ScreenHeight());
    // Initialize balls with different positions, velocities, and colors
    balls.emplace_back(olc::vf2d(30, 30), olc::vf2d(50, 80), 25.0f, olc::RED);
    balls.emplace_back(olc::vf2d(100, 100), olc::vf2d(-60, 40), 25.0f, olc::BLUE);

    // Create threads for each ball
    for (auto& ball : balls) {
        threads.emplace_back([&](Ball& b) {
            while (true) {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [&] { return updateFlag || exitFlag; });
                if (exitFlag) break;
                b.Update(elapsedTime, screenSize);
            }
        }, std::ref(ball));
    }

    return true;
}

bool BouncingBalls::OnUserUpdate(float fElapsedTime) {
    // Update screen size (if changed) and elapsed time
    // Screen size currently commented to test what happens when window size is changed
    // screenSize = olc::vi2d(ScreenWidth(), ScreenHeight());
    elapsedTime = fElapsedTime;

    // Signal the threads to update ball positions
    {
        std::lock_guard<std::mutex> lock(mtx);
        updateFlag = true;
    }
    cv.notify_all();

    Clear(olc::BLACK);

    // Update and draw balls
    for (auto& ball : balls) {
        //Ball::Update method is run bu thread
        // ball.Update(fElapsedTime, olc::vi2d(ScreenWidth(), ScreenHeight()));
        ball.Draw(this);
    }

    // Check for collisions and resolve them
    // for (size_t i = 0; i < balls.size(); ++i) {
    //     for (size_t j = i + 1; j < balls.size(); ++j) {
    //         if (balls[i].IsCollidingWith(balls[j])) {
    //             balls[i].ResolveCollision(balls[j]);
    //         }
    //     }
    // }

    // Reset update flag
    {
        std::lock_guard<std::mutex> lock(mtx);
        updateFlag = false;
    }

    return true;
}

bool BouncingBalls::OnUserDestroy() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        exitFlag = true;
    }
    cv.notify_all();
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
    return true;
}
