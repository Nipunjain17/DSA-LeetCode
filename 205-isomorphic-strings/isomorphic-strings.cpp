class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> st;
        unordered_map<char, char> ts;

        for(int i=0; i<s.length(); i++){
            char sc = s[i];
            char tc = t[i];

            if(st.count(sc) && st[sc] != tc) return false;

            if(ts.count(tc) && ts[tc] != sc) return false;

            st[sc] = tc;
            ts[tc] = sc;
        }
        return true;
    }
};