#include <iostream>
#include <string>
using namespace std;
// Function to draw the Tic-Tac-Toe board
void drawBoard(char board[3][3]) {
    cout << "   0   1   2\n";
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n";
        cout << "  -----------\n";
    }
}
bool checkWinner(char board[3][3]){
    bool winner = false;
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            winner = true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            winner = true;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        winner = true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        winner = true;
    }
    if (winner) {
        // TODO: Handle the case when a winner is found
        cout << "We have a winner!" << std::endl;
        return true;
    }
    
    return false;
}


int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col;
    // Game loop
    while (true) {
        // Draw the board
        drawBoard(board);
        // Get user input
        cout << "Player X, enter row (0-2): ";
        cin >> row;
        cout << "Player X, enter column (0-2): ";
        cin >> col;
        // Update the board with the player's move
        board[row][col] = 'X';
        // Check for a winner
        if(checkWinner(board)){
            drawBoard(board);
            return 0;
        }
        

        // Draw the board again
        drawBoard(board);

        // Get user input
        cout << "Player O, enter row (0-2): ";
        cin >> row;
        cout << "Player O, enter column (0-2): ";
        cin >> col;

        // Update the board with the player's move
        board[row][col] = 'O';

        // Check for a winner
        if(checkWinner(board)){
            drawBoard(board);
            return 0;
        }

    }
}