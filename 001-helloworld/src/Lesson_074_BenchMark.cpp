//
// Created by leixing on 2024/4/26.
//

#include "Lesson_074_BenchMark.h"
#include <chrono>
#include <iostream>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> mStart;
    std::chrono::time_point<std::chrono::high_resolution_clock> mEnd;

public:
    Timer() {
        mStart = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        mEnd = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(mStart).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(mEnd).time_since_epoch().count();
        auto duration = end - start;
        auto ms = duration * 0.001;
        std::cout << duration << "us (" << ms << " ms)\n";
    }
};

void benchMarkTest() {
    {
        Timer timer;

        int value = 0;
        for (int i = 0; i < 1000000; i++) {
            value += 2;
        }
        std::cout << value << std::endl;
    }
}