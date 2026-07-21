class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        stack<char> st;
        for(auto ch : s){
            if(ch == '(' || (ch >= 'a' && ch <= 'z')){
                st.push(ch);
            }
            else if(ch == ')'){
                string store = "";
                while(!st.empty() && st.top() != '('){
                    store += st.top();
                    st.pop();
                }

                st.pop(); // when find it '(' then pop it!
                // push the character into stack
                for(auto str : store){
                    st.push(str);    
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            char ch = st.top();
            ans += ch;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};