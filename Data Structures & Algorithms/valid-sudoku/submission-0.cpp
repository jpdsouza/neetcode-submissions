class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> row[9];
        unordered_map<char, int> col[9];
        unordered_map<char, int> square[9];

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char ch = board[i][j];

                if (ch == '.') continue;

                if (ch < '1' || ch > '9') return false;

                // Check row
                row[i][ch]++;
                if (row[i][ch] > 1) return false;

                // Check column
                col[j][ch]++;
                if (col[j][ch] > 1) return false;

                // Check 3x3 square
                int boxIndex = (i / 3) * 3 + (j / 3);
                square[boxIndex][ch]++;
                if (square[boxIndex][ch] > 1) return false;
            }
        }

        return true;
    }
};
