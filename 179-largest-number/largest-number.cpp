class Solution {
public:
    bool static compare(string &s1, string &s2){
        return s1+s2 > s2+s1;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;

        for(int i=0; i<n; i++){
            ans.push_back(to_string(nums[i]));
        }

        sort(ans.begin(), ans.end(), compare);
        
        if(ans[0] == "0") return "0";

        string result = "";
        for(int i=0; i<n; i++){
            result += ans[i];
        }

        return result;
    }
};