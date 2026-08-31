class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merge;
        for(auto x : intervals){
            if(!merge.empty() && x[0] <= merge.back()[1]){
                int u = merge.back()[0], v = merge.back()[1];
                merge.pop_back();

                if(v > x[1]){
                    merge.push_back({u, v});
                }
                else{
                    merge.push_back({u, x[1]});
                }
            }
            else{
                merge.push_back({x[0], x[1]});
            }
        }

        return merge;
    }
};