class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<vector<int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }
            }
        }
        
        int maxi = 0;
        vector<int>dx = {-1, 1, 0, 0};
        vector<int>dy = {0, 0, -1, 1};
        
        while(!q.empty()){
            vector<int> v = q.front();
            q.pop();
            
            int i = v[0], j = v[1], t = v[2];
            maxi = max(t, maxi);
            
            for(int k=0; k<4; k++){
                int x = i + dx[k], y = j + dy[k];
                
                if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
                    grid[x][y] = 2;
                    q.push({x,y,t+1});
                }
            }
        }
        
         for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    maxi = -1;
                }
            }
        }
        return maxi;
    }
};