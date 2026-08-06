class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> hset;

        for(auto x : arr){
            if(!hset.empty() && hset.find(x *2) != hset.end()){
                return true;
            }
            else if(x%2 == 0 && hset.find(x/2) != hset.end()){
                return true;
            }

            hset.insert(x);
        }

        return false;
    }
};