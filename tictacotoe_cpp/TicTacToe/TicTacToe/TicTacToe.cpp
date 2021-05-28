#include <iostream>
using namespace std;

int board[9];

void printBoard();
void playerMove(int);
bool winCheck(int);
bool playAgain();
void printBoardInt();

int main() {
    while (true) {
        cout << "Welcome to Tic Tac Toe! \nStarting game..." << endl;
        for (int i = 0; i < 9; i++)
            board[i] = 0;
        
        bool newTurn = true;
        bool hasWon = true;

        while (true) {
            int player = newTurn ? 1 : 2;

            playerMove(player);
            hasWon = winCheck(player);

            if (hasWon)
                break;

            newTurn = !newTurn;
        }
        printBoard();

        bool newGame = playAgain();
        if (newGame)
            continue;

        cout << "\nExiting game..." << endl;
        break;
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
    cout << "\n";
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
    cout << "\n";
}

//debug function to show board with int numbers
void printBoardInt() {
    cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        for (int j = i; j < i + 3; j++) {
            cout << board[j];
        }
        cout << "\n";
    }
}

bool playAgain() {
    cout << "Play again? \n[1] yes \n[2] no" << endl;
    int input = 0;
    while (true) {
        cin >> input;
        if (input < 1 || input > 2) {
            cout << "Invalid input: number must be 1 or 2 => ";
            continue;
        }
        break;
    }
    return input == 1;
}

//TODO refactor this function
bool winCheck(int player) {
    //top row
    if (board[0] == player && board[1] == player && board[2] == player) {
        cout << "\nPlayer " << player << " won top row!" << endl;
        return true;
    }
    //mid row
    if (board[3] == player && board[4] == player && board[5] == player) {
        cout << "\nPlayer " << player << " won middle row!" << endl;
        return true;
    }
    //bot row
    if (board[6] == player && board[7] == player && board[8] == player) {
        cout << "\nPlayer " << player << " won bot row!" << endl;
        return true;
    }
    //left col
    if (board[0] == player && board[3] == player && board[6] == player) {
        cout << "\nPlayer " << player << " won left column!" << endl;
        return true;
    }
    //mid col
    if (board[1] == player && board[4] == player && board[7] == player) {
        cout << "\nPlayer " << player << " won middle column!" << endl;
        return true;
    }
    //right col
    if (board[2] == player && board[5] == player && board[8] == player) {
        cout << "\nPlayer " << player << " won right column!" << endl;
        return true;
    }
    //diagonal top left to bot right
    if (board[0] == player && board[4] == player && board[8] == player) {
        cout << "\nPlayer " << player << " won diagonal!" << endl;
        return true;
    }
    //diagnoal top right to bot left
    if (board[2] == player && board[4] == player && board[6] == player) {
        cout << "\nPlayer " << player << " won diagonal!" << endl;
        return true;
    }

    return false;
}