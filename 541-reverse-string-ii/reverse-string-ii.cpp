class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();

        for(int i=0; i<n; i += 2*k){
            int j = min(i + k , (int)s.length());

            reverse(begin(s) + i , begin(s) + j);
        }
        return s;
    }
};