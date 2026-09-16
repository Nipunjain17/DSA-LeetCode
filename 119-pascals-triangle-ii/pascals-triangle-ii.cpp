class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> prev(1,1);

        for(int i=0; i<n; i++){
            vector<int> curr;
            curr.push_back(1);
            
            for(int j=1; j<prev.size(); j++){
                curr.push_back(prev[j-1] + prev[j]);
            }
            curr.push_back(1);

            prev = curr;
        }

        return prev;
    }
};