class Solution {
public:
    struct cmp{
          bool operator()(const pair<int, string>& a,
                        const pair<int, string>& b) const{
            if(a.first != b.first){
                return a.first < b.first;
            }

            return a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for(auto str : words){
            map[str]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> maxHeap;

        for(auto &x : map){
            maxHeap.push({x.second, x.first});            
        }

        vector<string> ans;
        while(k--){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }
};