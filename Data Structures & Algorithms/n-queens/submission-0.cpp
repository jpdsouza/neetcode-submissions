class Solution {
public:
    vector<vector<string>> result;
    unordered_set<int> col;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;
    int queens;

    inline bool isSafe(int &r, int &c)
    {
        if(col.count(c))
            return false;
        else if(negDiag.count(r - c))
            return false;
        else if(posDiag.count(r + c))
            return false;
        else
            return true;
    }
    void backtrack(vector<string> board, int r)
    {
        if(r == queens)
        {
            result.push_back(board);
            return;
        }
        for(int c = 0; c<queens; c++)
        {
            if(isSafe(r, c))
            {
                board[r][c] = 'Q';
                col.insert(c);
                negDiag.insert(r - c);
                posDiag.insert(r + c);

                backtrack(board, r+1);

                board[r][c] = '.';
                col.erase(c);
                negDiag.erase(r - c);
                posDiag.erase(r + c);
            }
            else
                continue;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        queens = n;
        backtrack(board, 0);
        return result;
    }
};
