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

    cout << "\033[35mWelcome to Tic-Tac-Toe!\033[0m" << endl;
    printBoard(board);
}