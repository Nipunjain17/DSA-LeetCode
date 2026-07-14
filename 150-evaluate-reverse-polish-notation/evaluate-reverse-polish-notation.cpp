class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto str : tokens){
            if(isdigit(str[0]) || (str.size() > 1 && str[0] == '-')){
                st.push(stoi(str));
            }
            else{
                int val1 = st.top();
                st.pop();

                int val2 = st.top();
                st.pop();
                
                if(str == "+"){
                    st.push(val2 + val1);
                }
                else if(str == "-"){
                    st.push(val2 - val1);
                }
                else if(str == "*"){
                    st.push(val2 * val1);
                }
                else if(str == "/"){
                    st.push(val2 /val1);
                }
            }
        }
        return st.top();
    }
};