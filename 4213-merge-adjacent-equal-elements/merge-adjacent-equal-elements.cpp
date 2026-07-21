class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();

        vector<long long> st;
        for(long long num : nums){
            while(!st.empty() && st.back() == num){
                num += st.back();
                st.pop_back();
            }

            st.push_back(num);
        }

        return st;
    }
};