class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }

        for(auto x : freq){
            if(x.second > n/3){
                result.push_back(x.first);
            }
        }
        return result;
    }
};