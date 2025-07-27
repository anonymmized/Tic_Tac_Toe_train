# Tic-Tac-Toe in C++

A simple console-based Tic-Tac-Toe game implemented in C++. Two players take turns placing 'X' or 'O' on a 3x3 board by entering numbers (1–9). The game supports choosing the first player, checking for a winner or draw, and playing multiple rounds.

## Features

- Two-player game with 'X' and 'O'.
- Colorful console output (red for 'X', blue for 'O', and more).
- Input validation for moves and player selection.
- Option to play again after each game.
- Checks for wins (rows, columns, diagonals) and draws.

## Requirements

- C++ compiler (e.g., g++ on macOS/Linux or MinGW on Windows).
- Terminal or command line to run the program.
- No external libraries required (uses standard C++ libraries: <iostream>).

## Installation and Running

- Clone or download the repository:
```bash
git clone '(https://github.com/anonymmized/Tic_Tac_Toe_train.git)'
```

- Navigate to the project directory:
```bash
cd tic-tac-toe
```

- Compile the code using g++:
```bash
g++ tic_tac_toe_fixed_play_again.cpp -o tic_tac_toe
```

- Run the executable:
```bash
./tic_tac_toe
```

## How to Play

- Run the program.
- Choose who starts ('X' or 'O') by entering 'X' or 'O' (case-insensitive).
- Enter a number (1–9) to place your symbol on the board:
```bash
| 1 | 2 | 3 |
-------------
| 4 | 5 | 6 |
-------------
| 7 | 8 | 9 |
```
- Players alternate turns until a winner is found (three symbols in a row, column, or diagonal) or the game ends in a draw.
- After the game, choose 'y' to play again or 'n' to exit.


## License

This project is open-source and available under the MIT License.