# Snake Game

English | [简体中文](README.md)

A classic Snake Game implemented in C language, developed as a course project for the C Programming Language Seminar at Harbin Institute of Technology.

## Features

- Classic Snake Game implemented in C
- Windows console-based graphical interface
- Snake body movement implemented using linked list data structure
- Complete game flow and interactive experience

## Game Introduction

1. **Game Interface**
   - Beautiful ASCII art welcome screen
   - Clear game boundaries and score display
   - Real-time player name and score display

2. **Game Controls**
   - Use WASD keys to control snake movement
   - P key to pause the game
   - Simple and intuitive menu system

3. **Game Mechanics**
   - Random food generation
   - Snake grows after eating food
   - Collision detection (walls and snake body)
   - Score tracking system

## Technical Implementation

### Core Data Structure
```c
typedef struct Snakes {
    int x;
    int y;
    struct Snakes *next;
} snake;
```

### Main Function Modules

- `welcome()`: Game welcome interface
- `menu()`: Game menu system
- `creatgraph()`: Game interface rendering
- `MovingBody()`: Snake movement logic
- `creatfood()`: Food generation
- `Judge()`: Game state judgment
- `Eating()`: Food consumption handling

## Game Screenshots

### Welcome Screen
![Welcome Screen](https://farsblog.oss-cn-beijing.aliyuncs.com/PicGo/202305152340496.png)

### Game Interface
![Game Interface](https://farsblog.oss-cn-beijing.aliyuncs.com/PicGo/202305152340104.png)

### Game Over Screen
![Game Over Screen](https://farsblog.oss-cn-beijing.aliyuncs.com/PicGo/202305152340900.png)

## System Architecture

![System Architecture](https://farsblog.oss-cn-beijing.aliyuncs.com/PicGo/202305152339857.png)

## Requirements

- Windows Operating System
- C Language Compiler
- Console with ASCII support

## How to Run

1. Clone or download the project code
2. Compile `main.c` using a C compiler
3. Run the generated executable file
4. Follow the on-screen instructions

## Project Structure

```
Snake-Game-C/
├── main.c          # Main program source code
├── main.exe        # Compiled executable
├── README.md       # Project documentation (Chinese)
├── README_EN.md    # Project documentation (English)
└── images/         # Project image resources
```

## Contributors

- Special thanks to the C Programming Language Seminar at Harbin Institute of Technology 