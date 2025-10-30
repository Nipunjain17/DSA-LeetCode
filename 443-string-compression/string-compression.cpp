class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int i = 0, index = 0;
        while(i < n){
            char currChar = chars[i];
            int count = 0; 

            while(i < n  && chars[i] == currChar){
                count++;
                i++;
            }
            chars[index++] = currChar;

            if(count > 1){
                string cnt = to_string(count);

                for(char c : cnt){
                    chars[index++] = c;
                }
            }
        }
        return index;
    }
};