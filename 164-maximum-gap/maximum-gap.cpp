class Solution {
public:
    int maximumGap(vector<int>& nums){
        sort(nums.begin(),nums.end());

        int n = nums.size();
        if(n <= 1){
            return 0;
        }

        int gap = 0;
        int maxGap = INT_MIN;

        int prev = nums[0];
        for(int i=1; i<n; i++){
            gap = nums[i] - prev;
            maxGap = max(maxGap,gap);
            prev = nums[i];
        }
        return maxGap;
    }
};