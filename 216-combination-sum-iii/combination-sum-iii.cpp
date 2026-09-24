class Solution {
public:
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> output; 
    void solve(int n, int k, vector<int>&ans, int index){
        // base condn
        if(n == 0 && k == 0){
            output.push_back(ans);
            return;
        }

        if(n < 0 || k < 0 || index >= 9){
            return;
        }

        // Include
        ans.push_back(arr[index]);
        solve(n -arr[index], k-1, ans, index +1);

        // backtrack 
        ans.pop_back();

        // exclude
        solve(n, k, ans, index +1);
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;
        solve(n, k, ans, 0);
        return output;
    }
};