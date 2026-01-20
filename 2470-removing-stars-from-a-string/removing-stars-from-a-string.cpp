class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for(auto ch:s){
            if(ch == '*'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(ch);
            }
        }

        s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};