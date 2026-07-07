class Solution {
private:
    void MakeSafe(int x, int y, vector<vector<int>> &grid){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0){
            return;
        }

        grid[x][y] = 0;

        MakeSafe(x-1, y, grid); // for Up
        MakeSafe(x+1, y, grid); // for Down
        MakeSafe(x, y-1, grid); // for Left
        MakeSafe(x, y+1, grid); // for Right

        return;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            // for first Column
            if(grid[i][0] == 1){
                MakeSafe(i, 0, grid);
            }
            // for last  column
            if(grid[i][m-1] == 1){
                MakeSafe(i, m-1, grid);
            }
        }

        for(int j=0;j<m; j++){
            // for first row 
            if(grid[0][j] == 1){
                MakeSafe(0, j, grid);
            }
            // for last row
            if(grid[n-1][j] == 1){
                MakeSafe(n-1, j, grid);
            }
        }
        int count = 0;
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};