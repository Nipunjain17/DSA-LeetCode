class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hmap; 
        for(auto ch : s){
            hmap[ch]++;
        }

        priority_queue<pair<int, char>> pq; 
        for(auto x : hmap){
            pq.push({x.second, x.first});
        }

        string ans = "";
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            while(it.first--){
                ans += it.second;
            }
        }
        return ans;
    }
};