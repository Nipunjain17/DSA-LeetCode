class Solution {
public:
    vector<string> result;

    bool isValid(string &s){
        if(s.size() > 1 && s[0] == '0') return false;
        int val = stoi(s);

        return (val >= 0 && val <= 255);
    }

    void backtrack(string &s, int index, int dots, string curr){
        if(dots == 4 && index == s.size()){
            curr.pop_back(); // removes the last dot
            result.push_back(curr);
            return;
        }
        
        if(dots > 4) return;

        for(int i = 1; i<=3 && index + i <= s.size(); i++){
            string part = s.substr(index,i);
            if(isValid(part)){
                backtrack(s, index+i, dots+1, curr+part+".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s,0,0,"");
        return result;
    }
};