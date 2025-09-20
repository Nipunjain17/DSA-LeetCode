class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        int n = nums.size();
        int i = 0;
        int j = n-1;
        while(i < j){
            if(nums[i] + nums[j] == target){
                ans[0] = i+1;
                ans[1] = j+1;
                return ans;
            }
            else if(nums[i] + nums[j] < target){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};