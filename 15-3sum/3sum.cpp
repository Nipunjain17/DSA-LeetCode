class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int target = 0;

        for(int i = n-1; i >= 0; i--) {
            // Skip duplicate values for i
            if(i < n-1 && nums[i] == nums[i+1]) continue;

            int left = 0, right = i-1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if(sum == target) {
                    ans.push_back({nums[left], nums[right], nums[i]});
                    
                    // Skip duplicates for left
                    while(left < right && nums[left] == nums[left+1]) left++;
                    // Skip duplicates for right
                    while(left < right && nums[right] == nums[right-1]) right--;

                    left++;
                    right--;
                }
                else if(sum > target) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return ans;
    }
};
