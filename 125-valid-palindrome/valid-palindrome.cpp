class Solution {
private:
    bool ValidChar(char ch){
        if( (ch >= 'a' && ch <='z') || (ch >= 'A' && ch <='Z') || (ch >= '0' && ch <='9')){
            return true;
        }
        return false;
    }   

    char toLower(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <='9')){
            return ch;
        }
        else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }
public:
    bool isPalindrome(string s) {
        int n = s.length();

        // Skip the non-alphanumeric characters
        string temp = "";
        for(int i=0; i<n; i++){
            if(ValidChar(s[i])){
                temp.push_back(s[i]);
            }
        }

        int m = temp.length();
        // Convert UpperCase Into LowerCase
        for(int i=0; i<m; i++){
            temp[i] = toLower(temp[i]);
        }

        int left = 0, right = m-1;
        while(left <= right){

            if(temp[left] != temp[right]){
                return false;
            }

            else{
                left++;
                right--;
            }
        }
        return true;
    }
};