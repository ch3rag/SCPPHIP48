#include <iostream>
#include "CHIP8.h"
#include <chrono>


int main(int argc, char ** argv) {
    
    if (argc < 2) {
        std :: cout << "Please provide path to ROM";
        return 0;
    }

    CHIP8 chip8;
    if(chip8.loadRom(argv[1])) {
        auto t1 = std::chrono::high_resolution_clock::now();
        auto t2 = std::chrono::high_resolution_clock::now();
        while(1) {
            t2 = std::chrono::high_resolution_clock::now();
            std::chrono::duration <float> elapsed = t2 - t1;
            float elapsedTime = elapsed.count();
            float sleepTime = 1 - elapsedTime;
            t1 = t2;
            Sleep(sleepTime > 0 ? sleepTime : 0);
            chip8.getInputs();
            chip8.cycle();
            if (chip8.drawFlag) {
                chip8.flushBuffer();
            }
        }
    } else {
        std :: cout << "Error While Loading ROM!";
    }
    return 0;
}

