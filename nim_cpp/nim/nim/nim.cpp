#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int playerScore = 0;
int aiScore = 0;
int matches = 24;

void displayMatches() {
    string matchesArt = "";

    for (int i = 0; i < matches; i++)
        matchesArt += "|";

    std::cout << "Matches: " << matchesArt << std::endl;
}

void playerTurn() {
    std::cout << "Player, draw matches: [1, 2, or 3]" << std::endl;
    int drawnMatches = 0;
    std::cin >> drawnMatches;
    drawnMatches = std::clamp(drawnMatches, 1, 3);

    if (drawnMatches > matches)
        drawnMatches = matches;

    std::cout << "Player draws " << drawnMatches << std::endl;
    matches -= drawnMatches;

    displayMatches();
}

int main() {
    while (true) {

        std::cout << "Welcome to Nim, starting new game..." << std::endl;

        while (true) {
            playerTurn();

            if (matches < 1) {
                std::cout << "AI won!" << endl;
                aiScore += 1;
                break;
            }
            
        }
        break;
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
