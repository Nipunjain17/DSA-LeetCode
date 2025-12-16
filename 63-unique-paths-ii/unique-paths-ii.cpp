class Solution{
private:
    bool isSafe(int x, int y, vector<vector<int>>& matrix, int n, int m){
        return (x >= 0 && x < n) && (y >= 0 && y < m) && matrix[x][y] == 0;
    }

    int solve(vector<vector<int>>& matrix, int n, int m,
    int x, int y, vector<vector<int>>& memo){
        // Base case: reached destination
        if(x == n-1 && y == m-1){
            return 1;
        }
        
        // Out of bounds or obstacle
        if(!isSafe(x, y, matrix, n, m)){
            return 0;
        }
        
        // Already computed? Return stored result
        if(memo[x][y] != -1){
            return memo[x][y];
        }

        // Recurse: Down + Right
        int down = solve(matrix, n, m, x+1, y, memo);
        int right = solve(matrix, n, m, x, y+1, memo);
        
        // Store and return result
        return memo[x][y] = down + right;
    }    
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        if(matrix[0][0] == 1 || matrix[n-1][m-1] == 1) return 0;

        vector<vector<int>> memo(n, vector<int>(m, -1));
        
        return solve(matrix, n, m, 0, 0, memo);
    }
};