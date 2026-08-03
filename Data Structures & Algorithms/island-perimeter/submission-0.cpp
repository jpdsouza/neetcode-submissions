class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int per = 0;

        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    if(i-1 < 0 || grid[i-1][j] == 0){
                        per++;
                    }
                    if(i+1 >= n || grid[i+1][j] == 0){
                        per++;
                    }
                    if(j-1 < 0 || grid[i][j-1] == 0){
                        per++;
                    }
                    if(j+1 >= m || grid[i][j+1] == 0){
                        per++;
                    }
                }
            }
        }

        return per;
    }
};

// class Solution {
// public:
//     int islandPerimeter(vector<vector<int>>& grid) {
//         int per = 0;

//         int n = grid.size();
//         int m = grid[0].size();
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j] == 1){
//                     if(i-1 < 0 || grid[i-1][j] == 0){
//                         per++;
//                     }
//                     if(i+1 >= n || grid[i+1][j] == 0){
//                         per++;
//                     }
//                     if(j-1 < 0 || grid[i][j-1] == 0){
//                         per++;
//                     }
//                     if(j+1 >= m || grid[i][j+1] == 0){
//                         per++;
//                     }
//                 }
//             }
//         }

//         return per;
//     }
// };