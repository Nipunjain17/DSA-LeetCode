class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    perimeter += 4;
                    for(int k=0; k<4; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
                            perimeter--;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};