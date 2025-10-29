class Solution {
public:
    bool isVowel(char& c){ // Check whetjher character is vowel or not
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
        c == 'A' || c =='E' || c == 'I' || c == 'O' || c == 'U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int n = s.length();

        int left = 0, right = n-1;
        while(left < right){
            if(!isVowel(s[left])){
                left++;
            }
            else if(!isVowel(
                s[right])){
                right--;
            }
            else{
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};