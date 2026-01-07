class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool counting = false;

        for(char ch : s){
            if(ch !=' '){
                if(!counting){
                    counting = true;
                    count = 1;
                }
                else{
                    count++;
                }
            }
            else{
                counting = false;
            }
        }
        return count++;
    }
};