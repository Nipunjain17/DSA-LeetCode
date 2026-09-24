class Solution {
public:  
    int n;
    vector<vector<int>> output;
    void solve(vector<int> &nums, vector<int> &ans, int index){
        if(index == n){
            output.push_back(ans);
            return;
        }
        // include the current element 
        ans.push_back(nums[index]);
        solve(nums, ans, index+1);
        
        // backtrack
        ans.pop_back();
        // skip the duplicate element
        while(index +1 < n && nums[index] == nums[index +1]){
            index++;
        }
        // exclude the current element 
        solve(nums, ans, index +1);
        return;
    } 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int>ans; 
        solve(nums, ans, 0);
        return output;
    }
};