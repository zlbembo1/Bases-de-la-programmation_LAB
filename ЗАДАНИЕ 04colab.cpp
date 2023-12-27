#include <iostream>

using namespace std;

const int MAX_N = 9; // Maximum value of n 

bool isSafe(char board[MAX_N][MAX_N], int row, int col, int n) {
    // Check vertical, horizontal, and diagonals
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q') {
            return false; // Check vertical
        }
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') {
            return false; // Check left diagonal
        }
        if (col + (row - i) < n && board[i][col + (row - i)] == 'Q') {
            return false; // Check right diagonal
        }
    }
    return true;
}

void printBoard(char board[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----" << endl;
}

void solveNQueens(int row, int n, char board[MAX_N][MAX_N]) {
    if (row == n) {
        // Reached the final row, print the current configuration
        printBoard(board, n);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            // Place the queen if the cell is safe
            board[row][col] = 'Q';
            solveNQueens(row + 1, n, board);
            board[row][col] = '.'; // Undo the choice to explore other options
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of n (1-9): ";
    cin >> n;

    if (n < 1 || n > 9) {
        cout << "Invalid input. n should be between 1 and 9 inclusive." << endl;
        return 1;
    }

    char board[MAX_N][MAX_N];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = '.'; // Initialize the board with empty cells
        }
    }

    solveNQueens(0, n, board);

    return 0;
}
