class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> hmap; 
        int curr = 0, count = 0;

        for(int i=0; i<n; i++){
            curr += nums[i];
            
            if(curr -k == 0){
                count++;
            }

            if(hmap.find(curr -k) != hmap.end()){
                count += hmap[curr -k];
            }

            hmap[curr]++;
        }
        return count;
    }
};