class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    
    int solve(vector<vector<int>>& grid, int x, int y){
        if(x == n) return 0;

        if(dp[x][y] != INT_MAX) return dp[x][y];

        int mini = INT_MAX;
        for(int j=0; j<m; j++){
            if(y == j) continue;
            mini = min(mini, solve(grid, x+1, j) + grid[x][y]);
        }
        return dp[x][y] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        if(n == 1 && m == 1) return grid[0][0];
        
        dp.assign(n, vector<int>(m, INT_MAX));
        int ans = INT_MAX;
        for(int col=0; col<m; col++){
            ans = min(ans, solve(grid, 0, col));
        }

        return ans;    
    }
};