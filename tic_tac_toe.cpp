#include <iostream>
using namespace std;

void printBoard(char board[3][3]) {
    cout << "\033[36m-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\033[36m| ";
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                cout << "\033[31m" << board[i][j] << "\033[0m | ";
            } else if  (board[i][j] == 'O') {
                cout << "\033[34m" << board[i][j] << "\033[0m | ";
            } else {
                cout << board[i][j] << " | ";
            }
        }
        cout << "\033[36m" << endl << "-------------" << endl;
    }
}

int main() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char currentPlayer;

    cout << "\033[35mWelcome to Tic-Tac-Toe!\033[0m" << endl;
    cout << "\033[35mPlayers take turns entering a number (1-9) to place X or O.\033[0m" << endl;

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

    printBoard(board);    
}