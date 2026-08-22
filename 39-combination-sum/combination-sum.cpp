class Solution {
public:
    vector<vector<int>> output;
    int n;
    void solve(vector<int> &candidates, int target, vector<int> &ans, int index, int sum){
        if(index >= n || sum > target) return;

        if(sum == target){
            output.push_back(ans);
            return;
        }

        ans.push_back(candidates[index]);
        solve(candidates, target, ans, index, sum +candidates[index]);

        ans.pop_back();
        solve(candidates, target, ans, index+1, sum);

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();

        vector<int> ans;
        solve(candidates, target, ans, 0, 0);

        return output;
    }
};