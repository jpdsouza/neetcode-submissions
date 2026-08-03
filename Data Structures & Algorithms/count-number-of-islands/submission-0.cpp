class Solution {
private:
    int row;
    int col;
    int count;
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid)
    {
        if(i < 0 || j < 0 || i == row || j == col || grid[i][j] == '0' || visited[i][j])
            return;
        visited[i][j] = true;

        dfs(i+1, j, visited, grid);
        dfs(i, j+1, visited, grid);
        dfs(i-1, j, visited, grid);
        dfs(i, j-1, visited, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        count = 0;
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, visited, grid);
                    count++;
                }
            }
        }
        return count;
    }
};

