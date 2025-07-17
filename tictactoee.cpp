#include <iostream>
#include <string>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char token = 'x';
bool tie = false;
string n1, n2;

// Function to display the Tic-Tac-Toe board
void functionOne() {
    cout << "   |   |   \n";
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << " \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << " \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << " \n";
    cout << "   |   |   \n";
}

// Function to take input from players and update the board
void functionTwo() {
    int digit;
    cout << (token == 'x' ? n1 : n2) << ", please enter a number (1-9): ";

    while (true) {
        cin >> digit;

        // Check if input is valid (between 1-9)
        if (digit < 1 || digit > 9) {
            cout << "Invalid input! Please enter a number between 1-9: ";
            continue;
        }

        // Convert digit to row & column
        row = (digit - 1) / 3;
        column = (digit - 1) % 3;

        // Check if the cell is already occupied
        if (space[row][column] == 'x' || space[row][column] == '0') {
            cout << "Cell already occupied! Choose another number: ";
        } else {
            break;  // Valid move
        }
    }

    // Update board with the move
    space[row][column] = token;
    token = (token == 'x') ? '0' : 'x';  // Switch turn
    functionOne();
}

// Function to check if there's a winner or a tie
bool functionThree() {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((space[i][0] == space[i][1] && space[i][1] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[1][i] == space[2][i])) {
            return true;
        }
    }

    // Check diagonals
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }

    // Check for a tie (no empty spaces left)
    tie = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != '0') {
                tie = false;  // If an empty space exists, it's not a tie
                return false;
            }
        }
    }

    return false;  // If no winner and no empty spaces, it's a tie
}

int main() {
    cout << "Enter name of first player: ";
    getline(cin, n1);
    cout << "Enter name of second player: ";
    getline(cin, n2);

    cout << n1 << " is Player 1 (X) and will play first.\n";
    cout << n2 << " is Player 2 (O) and will play second.\n";

    while (!functionThree()) {
        functionOne();
        functionTwo();
    }

    // Announce the winner or tie
    if (!tie) {
        if (token == '0') {  // Last move was 'x', so player 'x' wins
            cout << n1 << " wins! ??" << endl;
        } else {  // Last move was '0', so player '0' wins
            cout << n2 << " wins! ??" << endl;
        }
    } else {
        cout << "It's a draw! ??" << endl;
    }

    return 0;
}

