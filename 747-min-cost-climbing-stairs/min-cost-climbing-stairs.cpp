class Solution {
public:
    // so this approach is recurrsion + memorizaiton
    int solve1(vector<int> &cost, int n, vector<int> &dp){
        // base case
        if(n == 0) return cost[0];
        
        if(n == 1) return cost[1];

        // if already calculate the cost for that step
        if(dp[n] != -1){
            return dp[n];
        }

        // calculating the cost of nth stair
        dp[n] = min(solve1(cost, n-1, dp), solve1(cost, n-2, dp)) + cost[n];
        return dp[n];
    }

    // this tabulation method
    int solve2(vector<int>& cost, int n){
        vector<int> dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
    
    int minCostClimbingStairs(vector<int>& cost){
        int n = cost.size();
        /*
        // table for memorization
        vector<int> dp(n+1, -1);
        // Either reaches from n-1 or n-2 stair
        int ans = min(solve1(cost, n-1, dp), solve2(cost, n-2, dp));*/
        return solve2(cost, n);
    }
};