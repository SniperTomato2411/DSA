#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int boxes[9][9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                int num = board[r][c] - '1';  // convert char '1'-'9' → 0-8
                int boxIndex = (r / 3) * 3 + (c / 3);

                if (rows[r][num] || cols[c][num] || boxes[boxIndex][num]) {
                    return false; // duplicate found
                }

                rows[r][num] = 1;
                cols[c][num] = 1;
                boxes[boxIndex][num] = 1;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Example Sudoku board (valid)
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','3'}
    };

    if (sol.isValidSudoku(board)) {
        cout << "The Sudoku board is VALID " << endl;
    } else {
        cout << "The Sudoku board is INVALID " << endl;
    }

    return 0;
}
