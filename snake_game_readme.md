# Snake Game (C++)

A classic terminal-based Snake game implementation showcasing modern C++ programming practices, object-oriented design principles, and cross-platform development techniques.

## Description

This project is a fully functional Snake game that runs in the terminal, built from the ground up using C++17. It demonstrates advanced programming concepts including object-oriented programming, modular architecture, multithreading for responsive input handling, and efficient use of STL data structures. The game features smooth gameplay, dynamic difficulty progression, and cross-platform compatibility for both Windows and Linux environments.

## Features

- **Intuitive Controls**: Navigate the snake using arrow keys or WASD for flexible gameplay
- **Smart Collision Detection**: Precise detection for food collection, wall collisions, and self-collision
- **Dynamic Difficulty**: Progressive level system with incrementally increasing snake speed
- **Multithreaded Architecture**: Separate thread for input handling ensures responsive controls without blocking game logic
- **Modular Design**: Clean separation of concerns with dedicated header and source files for each component
- **Cross-Platform Support**: Conditional compilation for seamless execution on Windows and Linux systems
- **Real-Time Rendering**: Smooth terminal-based graphics with efficient screen updates

## Technologies Used

- **C++17**: Modern C++ standard with enhanced features
- **Object-Oriented Programming**: Encapsulation, inheritance, and polymorphism
- **Standard Template Library (STL)**: Utilizes `std::deque` for snake body management, `std::thread` for multithreading
- **Multithreading**: `std::thread` and `std::mutex` for concurrent input processing
- **Platform-Specific APIs**: Windows API (`conio.h`, `windows.h`) and Linux terminal control (`termios.h`, `unistd.h`)

## Project Structure

```
snake-game/
├── include/
│   ├── Game.h
│   ├── Snake.h
│   ├── Food.h
│   └── Input.h
├── src/
│   ├── main.cpp
│   ├── Game.cpp
│   ├── Snake.cpp
│   ├── Food.cpp
│   └── Input.cpp
├── build/
│   └── (compiled binaries and CMake output)
├── CMakeLists.txt
└── README.md
```

### Folder Descriptions

- **include/**: Contains all header files (`.h`) defining class interfaces and declarations
- **src/**: Contains all source files (`.cpp`) with implementation details
- **build/**: Directory for compiled executables and CMake-generated files

## Installation & Compilation

### Prerequisites

- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.10+ (optional, for CMake build)

### Option 1: Compile with g++

Navigate to the project root directory and run:

```bash
# Compile all source files
g++ -std=c++17 -pthread -I include src/*.cpp -o build/snake_game

# Run the game
./build/snake_game
```

**For Windows (using MinGW):**
```bash
g++ -std=c++17 -I include src/*.cpp -o build/snake_game.exe
build\snake_game.exe
```

### Option 2: Compile with CMake

```bash
# Create and enter build directory
mkdir -p build
cd build

# Generate build files
cmake ..

# Compile the project
cmake --build .

# Run the game
./snake_game       # Linux/macOS
# or
snake_game.exe     # Windows
```

## Game Controls

| Key | Action |
|-----|--------|
| **↑** or **W** | Move Up |
| **↓** or **S** | Move Down |
| **←** or **A** | Move Left |
| **→** or **D** | Move Right |
| **Q** | Quit Game |

## Gameplay

1. Control the snake to eat the food (`*` or `@`) that appears randomly on the screen
2. Each food item consumed increases the snake's length by one segment
3. The game speed increases progressively as you advance through levels
4. Avoid colliding with walls or the snake's own body
5. Try to achieve the highest score possible!

## Future Enhancements

This project serves as a foundation for additional features:

- **High Score Persistence**: Implement file I/O to save and load high scores across game sessions
- **Power-Ups**: Add special items that provide temporary abilities (speed boost, invincibility, etc.)
- **Obstacles**: Introduce static or moving obstacles to increase difficulty
- **Multiplayer Mode**: Two-player competitive or cooperative gameplay
- **GUI Version**: Migrate to a graphical interface using SFML or SDL2 for enhanced visuals
- **Sound Effects**: Audio feedback for actions and events
- **Customizable Settings**: Configurable board size, speed, and difficulty

## Learning Outcomes

This project demonstrates proficiency in several critical areas of software development:

**Object-Oriented Programming**: The codebase employs proper encapsulation with distinct classes for game logic, snake behavior, food management, and input handling. Each class has well-defined responsibilities, promoting maintainability and extensibility.

**Multithreading & Concurrency**: Implements thread-safe input handling using `std::thread` and `std::mutex`, preventing race conditions while maintaining responsive gameplay. This showcases understanding of concurrent programming challenges and solutions.

**Data Structures**: Utilizes `std::deque` for efficient snake body management, enabling constant-time insertion and deletion at both ends—essential for smooth snake movement and growth mechanics.

**Modular Design**: The project structure separates interface declarations from implementations, following best practices for large-scale C++ development. This modularity facilitates testing, debugging, and collaborative development.

**Cross-Platform Development**: Demonstrates conditional compilation techniques and platform-specific API usage, highlighting the ability to write portable code that adapts to different operating system environments.

## License

This project is open source and available for educational purposes.

## Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the issues page or submit a pull request.

---

**Author**: Swayam Prakash
**Project Link**: [\[GitHub Repository URL\]](https://github.com/swayxm-20/Snakegame-Cpp)