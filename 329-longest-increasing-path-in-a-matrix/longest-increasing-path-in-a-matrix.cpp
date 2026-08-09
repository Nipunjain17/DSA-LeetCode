class Solution {
public:
    bool isSafe(vector<vector<int>> &matrix, int x, int y, int prev){
        if(x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] > prev){
            return true;
        }
        else{
            return false;
        }
    }
    
    int solve(vector<vector<int>> &matrix, int x, int y, vector<vector<int>> &memo){
        // already calculated
        if(memo[x][y] != -1){
            return memo[x][y];
        }
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        int ans = 1;
        for(int k=0; k<4; k++){
            int newX = x + dx[k];
            int newY = y + dy[k];
            
            if(isSafe(matrix, newX, newY, matrix[x][y])){
                ans = max(ans, 1 + solve(matrix, newX, newY, memo));
            }
        }
        
        // store the ans of that problem 
        memo[x][y] = ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxPath = 1;
        vector<vector<int>> memo(n, vector<int>(m, -1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                maxPath = max(maxPath, solve(matrix, i, j, memo));
            }
        }

        return maxPath;
    }
};