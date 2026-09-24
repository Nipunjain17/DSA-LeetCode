class Solution {
public:
    vector<vector<int>> output;
    int n;
    void solve(vector<int>& candidates, int target, vector<int>&ans, int index){
        // if our sum reaches the output
        if(target == 0){
            output.push_back(ans);
            return;
        }

        for(int i=index; i<n; i++){
            // skip the duplicates
            if(i > index && candidates[i] == candidates[i-1]) continue;

            if(candidates[i] > target) break;

            ans.push_back(candidates[i]);
            solve(candidates, target -candidates[i], ans, i+1);

            ans.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> ans;
        solve(candidates, target, ans, 0);

        return output;
    }
};