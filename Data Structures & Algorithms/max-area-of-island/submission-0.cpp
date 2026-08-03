class Solution {
private:
    int row, col;

    int dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        if (r < 0 || c < 0 || r >= row || c >= col || visited[r][c] || grid[r][c] == 0)
            return 0;

        visited[r][c] = true;

        return 1 + dfs(r+1, c, visited, grid)
                 + dfs(r-1, c, visited, grid)
                 + dfs(r, c+1, visited, grid)
                 + dfs(r, c-1, visited, grid);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int maxArea = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j, visited, grid));
                }
            }
        }
        return maxArea;
    }
};
