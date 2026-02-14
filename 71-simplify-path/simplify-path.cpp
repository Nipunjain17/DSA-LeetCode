class Solution {
public:
    string simplifyPath(string path) {
        string result;
        stack<string> st;

        for(int i=0; i<path.size(); ++i){
            
            // Neglect the slash
            if(path[i] == '/') continue;

            string temp; // only store the name , "." and ".."
            // add the directory name between the two slash
            while(i<path.size() && path[i] != '/'){
                // add the path to string
                temp += path[i];
                ++i;
            }

            // Neglect the single period
            if(temp == ".") continue; 

            // Remove the previous directory from the stack
            else if(temp == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                // Stack will only stores only the name of directory
                st.push(temp);
            }
        }

        // adding all the directory name in the result string
        while(!st.empty()){
            result = "/" + st.top() + result;
            st.pop();
        }

        // String has no element 
        if(result.size() == 0) return "/";

        return result;
    }
};