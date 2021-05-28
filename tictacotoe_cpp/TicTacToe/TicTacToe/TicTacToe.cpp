#include <iostream>
using namespace std;

int board[9];
bool player = 1;

void printBoard();
void playerMove(int);

int main() {
    while (true) {
        playerMove(1);
        playerMove(2);
    }
}

void playerMove(int player) {
    printBoard();
    cout << "Player " << player << ": Pick an open square [1-9] => ";
    int move = 0;

    while (true) {
        cin >> move;
        if (move < 1 || move > 9) {
            cout << "Invalid input: number must be within 1 to 9 => ";
            continue;
        }
        move--;
        if (board[move] != 0) {
            cout << "Invalid input: position already occupied, choose an open position => ";
            continue;
        }
        break;
    }

    board[move] = player;
}

void printBoard() {
    for (int i = 0; i < 9; i += 3) {
        for (int j = i; j < i + 3; j++) {
            int mark = 0;
            switch (board[j]) {
                case 1: 
                    mark = 1; 
                    break;
                case 2: 
                    mark = 2; 
                    break;
            }
            cout << mark;
        }
        cout << "\n";
    }
}