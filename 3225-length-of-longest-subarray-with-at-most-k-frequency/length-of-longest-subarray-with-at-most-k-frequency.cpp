class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> hmap;
        int left = 0;

        int maxLen = 0;
        for(int right=0; right<n; right++){
            hmap[nums[right]]++;
            
            while(hmap[nums[right]] > k){
                hmap[nums[left]]--;
                left++;
            }

            maxLen = max(maxLen, right -left +1);
        }
        return maxLen;
    }
};