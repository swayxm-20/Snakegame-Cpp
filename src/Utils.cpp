#include "../include/Utils.h"

#include <iostream>

#ifdef _WIN32

int kbhit() { return _kbhit(); }
int getch() { return _getch(); }

void initTerminal() {
    // enable ANSI escape processing on modern Windows consoles
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

void clearScreen() { std::cout << "\x1b[2J\x1b[H"; }
void sleepMs(int ms) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }

#else // POSIX

static struct termios orig_termios;

static void reset_terminal_mode() {
    tcsetattr(0, TCSANOW, &orig_termios);
}

static void set_conio_terminal_mode() {
    struct termios new_termios;
    tcgetattr(0, &orig_termios);
    new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &new_termios);
    atexit(reset_terminal_mode);
}

int kbhit() {
    static bool initialized = false;
    if (!initialized) { set_conio_terminal_mode(); initialized = true; }
    int oldf = fcntl(0, F_GETFL, 0);
    fcntl(0, F_SETFL, oldf | O_NONBLOCK);
    int ch = getchar();
    if (ch != EOF) {
        ungetc(ch, stdin);
        fcntl(0, F_SETFL, oldf);
        return 1;
    }
    fcntl(0, F_SETFL, oldf);
    return 0;
}

int getch() {
    static bool initialized = false;
    if (!initialized) { set_conio_terminal_mode(); initialized = true; }
    int c = getchar();
    return c;
}

void initTerminal() {
    // no-op (termios set lazily in kbhit/getch)
}

void clearScreen() { std::cout << "\x1b[2J\x1b[H"; }
void sleepMs(int ms) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }

#endif
