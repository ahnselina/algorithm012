/*200. 岛屿数量*/
class Solution {
public:
    void DFS(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') 
            return;
        
        grid[i][j] = '0';
        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);
        return;
    }

    int numIslands(vector<vector<char>>& grid) {;
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
               if (grid[i][j] == '1') {
                    DFS(grid, i, j);
                    count++;
               }
            }
        }

        return count;
    }
};