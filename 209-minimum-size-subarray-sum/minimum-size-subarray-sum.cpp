class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0, minlen = INT_MAX;
        
        int right = 0, left = 0;
        for(right=0; right<n; right++){
            sum += nums[right];

            while(sum >= target){
                minlen = min(right -left +1, minlen);
                sum = sum - nums[left];
                left++;
            }
        }

        return (minlen != INT_MAX)? minlen : 0;
    }
};