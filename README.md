# Tic Tac Toe in C++

## Overview

This is a simple command-line Tic Tac Toe game implemented in C++. The game allows a human player to compete against the computer. The primary objective of this project was to learn and understand pointers in C++. By working with arrays, function pointers, and passing data between functions using pointers, this project aims to strengthen skills that I am learning in my Data Structures class, particularly in memory management and data manipulation.

## How It Works

- The game is played on a 3x3 grid, represented by a one-dimensional array.
- The player is represented by the symbol 'X' and the computer by 'O'.
- The game continues in turns, with the player choosing a position on the grid, followed by the computer's move.
- The game ends when either the player or the computer wins by placing three of their symbols in a row, column, or diagonal, or when the grid is full and the game is a tie.

## Key Features

- **Player vs Computer**: Play against a simple AI that randomly selects its moves.
- **Win/Tie Detection**: The game can detect a win or a tie and will end accordingly.
- **Pointers Usage**: The game uses pointers to manage the board and player/computer moves, helping to reinforce the understanding of pointers in C++.

## How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/tic-tac-toe-cpp.git
2. Navigate to the project directory:
   ```bash
   cd tic-tac-toe-cpp
3. Compile the code using a C++ compiler:
   ```bash
   g++ -o tictactoe main.cpp
4. Run
   ```bash
   ./tictactoe
