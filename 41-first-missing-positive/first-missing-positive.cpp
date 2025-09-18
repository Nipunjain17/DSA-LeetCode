class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                ans.push_back(nums[i]);
            }
        }

        int target = 1;

        int m = ans.size(); 

        for(int i=0;i<m;i++){
            if(ans[i] == target){
                target++;
            }
            else if(nums[i] > target){
                return target;
            }
        }
        return target;
    }
};