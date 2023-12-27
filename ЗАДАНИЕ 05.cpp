#include <iostream>
#include <vector> //to create and manipulate dynamic arrays like matrices
#include <stack> //implements stack data structure

using namespace std;

bool validInput(char c) {//to check user's input values
    return c == '0' || c == '1';
}

int Rectangle(vector<vector<char>>& matrix) {//takes 2d vector, returns int
    if (matrix.empty() || matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    // Check conditions
    if (rows == matrix.size() && cols == matrix[0].size() && rows >= 1 && rows <= 200 && cols >= 1 && cols <= 200) {
        vector<int> heights(cols, 0);
        int maxArea = 0;//initialize var to store max area 

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                char input;
                do {
                    cout << "Enter value (0 or 1) for matrix[" << i << "][" << j << "]: ";
                    cin >> input;

                    if (!validInput(input)) {
                        cout << "Invalid input. Please enter '0' or '1'." << endl;
                    }
                } while (!validInput(input));

                matrix[i][j] = input;
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }

            stack<int> s;
            for (int j = 0; j <= cols; ++j) {
                while (!s.empty() && (j == cols || heights[j] < heights[s.top()])) {
                    int height = heights[s.top()];
                    s.pop();
                    int width = s.empty() ? -1 : s.top();
                    maxArea = max(maxArea, height * (j - width - 1));
                }
                s.push(j);
            }
        }

        return maxArea;
    } else {
        cout << "Invalid input size or range." << endl;
        return 0;
    }
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows (1-200): ";
    cin >> rows;
    cout << "Enter the number of columns (1-200): ";
    cin >> cols;

    vector<vector<char>> matrix(rows, vector<char>(cols, '0'));

    int result = Rectangle(matrix);
    cout << "Maximum rectangle area: " << result << endl;

    return 0;
}
