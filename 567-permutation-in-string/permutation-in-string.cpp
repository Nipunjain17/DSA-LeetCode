class Solution {
private:    
    bool checkEqual(int a[26], int b[26]){
        // Checking where element is same or not 
        for(int i=0; i<26; i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int windowSize = s1.length(), n = s2.size();

        // Base Condition
        if(n < windowSize){
            return false;
        }
        // Character count aaray
        int count1 [26] = {0};
        for(int i=0; i<windowSize; i++){
            int index = s1[i] - 'a';
            count1[index]++;
        }

        int i = 0;
        int count2 [26]= {0};
        // For first time run
        while(i < windowSize){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        if(checkEqual(count1,count2)){
            return true;
        }

        // To process element further 
        while(i < n){
            // Inserting the count of new element 
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;

            // Deleting the count of old element 
            char oldChar = s2[i - windowSize];
            index = oldChar - 'a';
            count2[index]--;
            i++;

            if(checkEqual(count1,count2)){
                return true;
            }
        }
        return false;
    }
};