class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        for(int i=0;i<n;i++){
            index = index^nums[i];
        }
        return index;
    }
};