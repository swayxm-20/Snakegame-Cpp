#ifndef UTILS_H
#define UTILS_H

#include <chrono>
#include <thread>

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

int kbhit();       // non-blocking keyboard check
int getch();       // blocking read of a single key (returns int)
void initTerminal();
void clearScreen();
void sleepMs(int ms);

#endif // UTILS_H
