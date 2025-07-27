#include <iostream>
using namespace std;

void printBoard(char board[3][3]) {
    cout << "\033[36m-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\033[36m| ";
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                cout << "\033[31m" << board[i][j] << "\033[0m | ";
            } else if (board[i][j] == 'O') {
                cout << "\033[34m" << board[i][j] << "\033[0m | ";
            } else {
                cout << board[i][j] << " | ";
            }
        }
        cout << "\033[36m" << endl << "-------------" << endl;
    }
}

bool isValidMove(char board[3][3], int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return move >= 1 && move <= 9 && board[row][col] != 'X' && board[row][col] != 'O';
}

char checkWinner(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    bool full = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                full = false;
            }
        }
    }

    if (full) return 'D';
    return ' ';
}

int main() {
    char playAgain;
    do {
        char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
        char currentPlayer;
        char winner = ' ';

        cout << "\033[35mWelcome to Tic-Tac-Toe!\033[0m" << endl;
        cout << "\033[35mPlayers take turns entering a number (1-9) to place X or O.\033[0m\n" << endl;

        do {
            cout << "\033[38;5;208mWho starts 'X' or 'O'? \033[0m";
            cin >> currentPlayer;
            if (currentPlayer == 'X' || currentPlayer == 'x' || currentPlayer == 'O' || currentPlayer == 'o') {
                currentPlayer = (currentPlayer == 'x') ? 'X' : (currentPlayer == 'o') ? 'O' : currentPlayer;
                cout << "\033[32mPlayer " << currentPlayer << " starts!\n" << endl;
                break;
            } else {
                cout << "\033[31mInvalid input! Enter 'X' or 'O'.\033[0m" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        } while (true);

        while (true) {
            printBoard(board);
            cout << "\033[38;5;208mPlayer " << currentPlayer << ", enter a number (1-9): \033[0m";
            int move;
            while (!(cin >> move) || !isValidMove(board, move)) {
                cout << "\033[31mInvalid move! Choose an empty cell (1-9): \033[0m";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            board[row][col] = currentPlayer;

            winner = checkWinner(board);
            if (winner != ' ') {
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        printBoard(board);
        if (winner == 'X' || winner == 'O') {
            cout << "\033[32mPlayer " << winner << " wins!\033[0m" << endl;
        } else if (winner == 'D') { 
            cout << "\033[33mIt's a draw!\033[0m" << endl;
        }

        cout << "\033[36mPlay again? (y/n): \033[0m";
        cin >> playAgain;
        cin.clear();
        cin.ignore(10000, '\n');
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\033[35mThanks for playing!\033[0m" << endl;
    return 0;
}