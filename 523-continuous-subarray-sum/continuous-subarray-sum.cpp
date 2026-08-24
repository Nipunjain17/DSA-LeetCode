class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> hmap;
        hmap[0] = -1;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int remaining = sum %k;

            if(hmap.find(remaining) != hmap.end()){
                if(i -hmap[remaining] > 1){
                    return true;
                }
            }
            else{
                hmap[remaining] = i;
            }
        }

        return false;
    }
};