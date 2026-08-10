class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
    
        unordered_set<int> hset;
        int maxi = INT_MIN, mini = INT_MAX;
        for(auto x : nums){
            maxi = max(maxi, x);
            mini = min(mini, x);

            hset.insert(x);
        }

        vector<int> ans;
        for(int i=mini; i<=maxi; i++){
            if(hset.find(i) == hset.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};