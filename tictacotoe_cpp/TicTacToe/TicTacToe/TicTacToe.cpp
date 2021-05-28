#include <iostream>
using namespace std;

int board[9];
bool player = 1;

void printBoard();

int main() {
    printBoard();

    cout << "Player 1: Pick an open square [1-9]:";
    int move = 0;
    cin >> move;
    move--;
    board[move] = 1;

    cout << "Player 2: Pick an open square [1-9]:";
    cin >> move;
    move--;
    board[move] = 2;

    printBoard();
}

void printBoard() {
    for (int i = 0; i < 9; i += 3) {
        for (int j = i; j < i + 3; j++) {
            cout << board[j];
        }
        cout << "\n";
    }
}