#ifndef _CHIP8_H_
#define _CHIP8_H_
#endif

#include <iostream>
#include <Windows.h>
class CHIP8 {
    public:
        bool loadRom(char[]);
        void flushBuffer();
        void cycle();
        void getInputs();
        bool drawFlag;
        CHIP8();
    private:
        int * memory;                       // 4098 KB 
        int * registerSet;                  // Array Of Size 16, 8  BIT EACN
        int * stack;                        // Array Of Size 16, 16 BIT EACH
        int * RPL_Flags;                    // 8 FLAGS
        wchar_t * displayBuffer;            // 32 X 64
        int pc;                             // PROGRAM COUNTER 16 BIT 
        int index;                          // INDEX REGISTER 16 BIT
        int delayTimer;                     // DELAY TIMER 8 BIT
        int soundTimer;                     // SOUND TIMEER 8 BIT
        int sp;                             // STACK POINTTER 8 BIT
        int instruction;                    // STORES CURRENT INSTRUCTION (16 BIT WIDE)
        int * keyStates;
        int x;
        int y;
        int coordIndex;
        int bit;
        int coordX;
        int coordY;
        int byte;
        int digit;
        int offset;
        int mask;
        int mode;
        HANDLE consoleHandle;
        DWORD charsWritten;
};