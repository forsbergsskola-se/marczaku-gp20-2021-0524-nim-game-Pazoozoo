#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <sstream>

int playerScore = 0;
int aiScore = 0;
int matches = 24;
int drawnMatches = 0;

void displayMatches() {
    std::string matchesArt = "";

    for (int i = 0; i < matches; i++)
        matchesArt += "|";

    std::cout << "Matches: " << matchesArt << "\n" << std::endl;
}

bool playerTurn() {
    std::string input = "";
    std::cout << "Player, draw matches: [1, 2, or 3]" << std::endl;
    std::cin >> input;
    drawnMatches = std::stoi(input);
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
        std::cout << "\nEnter 1 to play again, or 2 to exit game" << std::endl;

        std::string input = "";
        std::cin >> input;
        int response = std::stoi(input);

        if (response != 2)
            continue;

        std::cout << "\nExiting game..." << std::endl;
        break;
    }
}
