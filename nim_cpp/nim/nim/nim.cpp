#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>

int playerScore = 0;
int aiScore = 0;
int matches = 24;
int drawnMatches = 0;

bool playerTurn();
bool aiTurn();
bool playAgain();
int playerInput(std::string);
void displayMatches();

int main() {
    while (true) {
        bool playing = 1;
        matches = 24;
        std::cout << "\nWelcome to Nim, starting new game...\n" << std::endl;

        while (playing) {
            playing = playerTurn();

            if (playing)
                playing = aiTurn();
        }

        std::cout << "\nScore: \n" << "  Player: " << playerScore << "\n  AI: " << aiScore << std::endl;
        bool newGame = playAgain();

        if (newGame)
            continue;

        std::cout << "\nExiting game..." << std::endl;
        break;
    }
}

bool playerTurn() {
    std::string drawMessage = "Player, draw matches : [1, 2, or 3]";
    drawnMatches = playerInput(drawMessage);
    drawnMatches = std::clamp(drawnMatches, 1, 3);

    if (drawnMatches > matches)
        drawnMatches = matches;

    std::cout << "Player drew " << drawnMatches << std::endl;
    matches -= drawnMatches;

    displayMatches();

    if (matches > 0)
        return true;

    std::cout << "AI won!" << std::endl;
    aiScore += 1;
    return false;
}

bool aiTurn() {
    switch (matches % 4) {
    case 0:
        drawnMatches = 3;
        break;
    case 1:
        drawnMatches = std::rand() % 3 + 1;
        break;
    case 2:
        drawnMatches = 1;
        break;
    case 3:
        drawnMatches = 2;
        break;
    }
    std::cout << "AI drew " << drawnMatches << std::endl;

    matches -= drawnMatches;
    displayMatches();

    if (matches > 0)
        return true;

    std::cout << "Player won!" << std::endl;
    playerScore += 1;
    return false;
}

bool playAgain() {
    std::string playAgainMessage = "\nEnter [1] to play again, or [2] to exit game";
    return playerInput(playAgainMessage) != 2;
}

int playerInput(std::string message) {
    std::string input;
    std::cout << message << std::endl;

    while (true) {
        std::cin >> input;

        if (input.size() > 1) {
            std::cout << "Invalid input, only one digit allowed!\n" << std::endl;
            continue;
        }

        if (!isdigit(input[0])) {
            std::cout << "Invalid input, only numbers allowed!\n" << std::endl;
            continue;
        }
        break;
    }
    return std::stoi(input);
}

void displayMatches() {
    std::string matchesArt = "";

    for (int i = 0; i < matches; i++)
        matchesArt += "|";

    std::cout << "Matches: " << matchesArt << "\n" << std::endl;
}