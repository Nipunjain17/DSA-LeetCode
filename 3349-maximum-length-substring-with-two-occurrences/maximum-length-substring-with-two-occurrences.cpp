class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        
        int maxLen = 0, k = 2, left = 0; 
        for(int right=0; right<n; right++){
            int index = s[right] -'a';
            freq[index]++;

            while(freq[index] > k){
                int idx = s[left] -'a';
                freq[idx]--;
                left++;
            }
            maxLen = max(maxLen, right - left +1);
        }

        return maxLen;
    }
};