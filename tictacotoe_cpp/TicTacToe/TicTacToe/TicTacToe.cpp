#include <iostream>
using namespace std;

int board[9];
bool player = 1;

void printBoard();
void playerMove(int);
bool winCheck(int);
void printBoardInt();

int main() {
    bool hasWon = 1;
    while (true) {
        playerMove(1);
        hasWon = winCheck(1);

        if (hasWon)
            break;

        playerMove(2);
        hasWon = winCheck(2);

        if (hasWon)
            break;
    }
    printBoardInt();
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
    cout << "\n" << endl;
    for (int i = 0; i < 9; i += 3) {
        for (int j = i; j < i + 3; j++) {
            char mark = '#';
            switch (board[j]) {
                case 1: 
                    mark = 'X';
                    break;
                case 2: 
                    mark = 'O';
                    break;
            }
            cout << mark;
        }
        cout << "\n";
    }
}

void printBoardInt() {
    cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        for (int j = i; j < i + 3; j++) {
            cout << board[j];
        }
        cout << "\n";
    }
}

bool winCheck(int player) {
    //top row
    if (board[0] == player && board[1] == player && board[2] == player) {
        cout << "Player " << player << " won top row " << endl;
        return 1;
    }
    //mid row
    if (board[3] == player && board[4] == player && board[5] == player) {
        cout << "Player " << player << " won middle row " << endl;
        return 1;
    }
    //bot row
    if (board[6] == player && board[7] == player && board[8] == player) {
        cout << "Player " << player << " won bot row " << endl;
        return 1;
    }
    //left col
    if (board[0] == player && board[3] == player && board[6] == player) {
        cout << "Player " << player << " won left column " << endl;
        return 1;
    }
    //mid col
    if (board[1] == player && board[4] == player && board[7] == player) {
        cout << "Player " << player << " won middle column " << endl;
        return 1;
    }
    //right col
    if (board[2] == player && board[5] == player && board[8] == player) {
        cout << "Player " << player << " won right column " << endl;
        return 1;
    }
    //diagonal top left to bot right
    if (board[0] == player && board[4] == player && board[8] == player) {
        cout << "Player " << player << " won diagonal " << endl;
        return 1;
    }
    //diagnoal top right to bot left
    if (board[2] == player && board[4] == player && board[6] == player) {
        cout << "Player " << player << " won diagonal " << endl;
        return 1;
    }

    return 0;
}