# Galaga Game Clone

A modern C++ implementation of the classic arcade game Galaga using the Cinder framework for graphics and gameplay.

## Overview

This project recreates the core mechanics of Galaga with the following features:

- Player-controlled battleship that can move and shoot
- Enemy ships that move downward in formations
- Score tracking with persistent high score
- Multiple lives system 
- Increasing difficulty through levels
- Arcade-style visuals and custom font

## Getting Started

### Prerequisites

- CMake 3.12+
- C++11 compatible compiler
- Cinder graphics framework
- Visual Studio 2019+ (Windows) or Xcode (macOS)

### Building the Project

1. Clone the repository
2. Install the arcade font from `resources/arcade_font.TTF`
3. Build using CMake:

```bash
mkdir build
cd build
cmake ..
```

4. Open the generated project files in your IDE
5. Build the galaga-game target

   
## Running the Game
Launch the compiled galaga-game executable.

### Controls
- Left/Right Arrow Keys - Move battleship
- Z - Fire bullet
- Close window to exit

### Implementation Details
The game is structured around these key components:

- Space - Main game container managing all entities
- GalagaApp - Cinder application wrapper handling rendering and input
- Battleship - Player-controlled ship
- Enemy - Enemy ships with movement patterns
- PlayerBullet - Projectile physics

The architecture uses modern C++ practices and is thoroughly unit tested using Catch2.

## Testing
Run the unit tests by building and running the galaga-test target.

## Notes

- High scores are persisted in resources/highscore.txt
- The game has no win condition - aim for the highest score possible
- Each level increases enemy count by 3x
- Each enemy destroyed awards 50 points
