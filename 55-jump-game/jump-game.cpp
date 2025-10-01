class Solution {
public:
    bool canJump(vector<int>& arr) {
        int maxReach = 0, n = arr.size();
        
        for(int i=0; i<n; i++) {
            if(i > maxReach) return false;   // can't reach this index
            maxReach = max(maxReach, i + arr[i]);
        }
        
        return true;
    }
};
