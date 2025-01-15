#include <bits/stdc++.h> // Using this header to save "time." All of the libraries are included when using this


// Using a 2D array

int main() {

    char board[3][3] = {

        {' ', ' ', ' '}, // White space indicates an empty tile
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };


    // Creating players
    // Game will always start with playerX 
    const char playerX = 'X';
    const char playerO = 'O';
    char currentPlayer = playerX; // Keeps track of the current player
    int row = -1;
    int column = -1;

    char winner = ' ';

    for (int i = 0; i < 9; i++) {
        // Printing board
        std::cout << "   |   |  " << "\n";
        std::cout << " " << board[0][0] <<" | " << board[0][1] << " | " << board[0][2] << "\n";
        std::cout << "___|___|___" << "\n";
        std::cout << "   |   |  " << "\n";
        std::cout << " " << board[1][0] <<" | " << board[1][1] << " |" << board[1][2] << "\n";
        std::cout << "___|___|___" << "\n";
        std::cout << "   |   |  " << "\n";
        std::cout << " " << board[2][0] <<" | " << board[2][1] << " | " << board[2][2] << "\n";


        if (winner != ' ') {

            break;

        }

        // Getting player output
        std::cout << "Current player is: " << currentPlayer << "\n";
        while (true) {
            std::cout << "Row and column from 0-2 EX: 0 2: ";
            std::cin >> row >> column;
            if (row < 0 || row > 2 || column < 0 || column > 2) {

                std::cout << "Invalid input, try again" << "\n"; 

            } else if (board[row][column] != ' ') {

                std::cout << "Tile is full, try again" << "\n";

            } else {

                break;

            }
            // Resetting values
            row = -1;
            column = -1; 

            std::cin.clear(); // Clear error flags
            std::cin.ignore(10000, '\n');

        }


        board[row][column] = currentPlayer;
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

        // Checking for winner
        for (int r = 0; r < 3; r++){

            if (board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][1] == board[row][2]) {

                winner = board[row][0];
                break; // Early exit just incase there is a winner at the first row
            
            }

        }

        // Checking for winner vertically
        for (int c = 0; c < 3; c++) {
            if (board[0][column] != ' ' && board[0][column] == board[1][column] && board[1][column] == board[2][column]) {
                winner = board[0][column];
                break;
            }
        }


        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                
                winner = board[0][0];

        } else if (board[0][2] != ' ' && board[0][2] == board [1][1] && board[1][1] == board[2][0]) {

            winner = board[0][2];

        }
    }

    if (winner != ' ') {

        std::cout << "PLayer " << winner << " YOU WIN!!!" << "\n";

    } else {
        std::cout << "TIE!" << "\n";
    }
}
