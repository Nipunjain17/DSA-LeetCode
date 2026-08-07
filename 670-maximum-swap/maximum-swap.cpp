class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);

        // store the index of the elements 
        unordered_map<int, int> hmap;
        for(int i=0; i<str.length(); i++){
            int n = str[i] -'0';
            hmap[n] = i;
        }

        for(int i=0; i<str.length(); i++){
            for(int n=9; n>str[i]- '0'; n--){
                if(hmap[n] > i){
                    swap(str[i], str[hmap[n]]);
                    return stoi(str);
                }
            }
        }

        return num;
    }
};