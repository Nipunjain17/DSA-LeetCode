class Solution {
public:
    string toLowerCase(string s) {
        if(s.length() == 0) return s;

        for(int i=0; i<s.length(); i++){
            s[i] = tolower(s[i]);
        }

        return s;
    }
};