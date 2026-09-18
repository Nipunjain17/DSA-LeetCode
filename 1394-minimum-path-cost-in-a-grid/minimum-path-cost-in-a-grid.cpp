class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& grid, vector<vector<int>>& moveCost, int x, int y){
        if(x == n-1) return grid[x][y];

        if(y < 0 || y >= m) return INT_MAX;

        if(dp[x][y] != -1) return dp[x][y];

        int ans = INT_MAX;
        for(int k=0; k<m; k++){
            ans = min(ans, grid[x][y] + moveCost[grid[x][y]][k] + solve(grid, moveCost, x+1, k));
        }

        return dp[x][y] = ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        n = grid.size(), m = grid[0].size();
        dp.assign(n, vector<int>(m, -1));
        
        int ans = INT_MAX;
        for(int col=0; col<m; col++){
            ans = min(ans, solve(grid, moveCost, 0, col));
        }

        return ans;
    }
};