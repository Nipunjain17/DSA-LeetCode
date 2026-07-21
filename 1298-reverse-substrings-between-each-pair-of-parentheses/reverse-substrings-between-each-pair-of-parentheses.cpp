class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        vector<int> pair(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int j = st.top();
                st.pop();

                pair[i] = j;
                pair[j] = i;
            }
        }

        string ans = "";
        int dirn = 1;
        for(int i=0; i<n; i += dirn){
            if(s[i] == '(' || s[i] == ')'){
                i = pair[i];
                dirn = - dirn;
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};