#include <iostream>
using namespace std;

int board[9];

void printBoard();

int main() {
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