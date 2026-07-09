class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> ans;

        set<pair<int, int>, greater<pair<int, int>>> maxSet;
        set<pair<int, int>> minSet;
        // adding elements of first window
        for(int i=0; i<k; i++){
            minSet.insert({nums[i], i});
        }

        // Transfering half top stuff of minSet to maxSet
        for(int i=0; i<k/2; i++){
            auto it = minSet.begin();
            maxSet.insert(*it);
            minSet.erase(it);
        }

        double median;
        if(k %2){
            median = minSet.begin()->first;
        }
        else{
            median = (1.0 * maxSet.begin()->first + minSet.begin()->first)/2.0;
        }
        ans.push_back(median);
        int right = k, left = 0;

        while(right < n){
            pair<int, int> remove ={nums[left], left};
            pair<int, int> add = {nums[right], right};
            int Signum = 1; //from which set element is removed
            if(maxSet.find(remove) != maxSet.end()){
                maxSet.erase(remove);
                Signum--;
            }
            else{
                minSet.erase(remove);
            }
            
            if(Signum){
                maxSet.insert(add);
                auto it = maxSet.begin();
                minSet.insert(*it);
                maxSet.erase(it);
            }
            else{
                minSet.insert(add);
                auto it = minSet.begin();
                maxSet.insert(*it);
                minSet.erase(it);
            }

            if(k %2){
                median = minSet.begin()->first;
            }
            else{
                median = (1.0 * maxSet.begin()->first + minSet.begin()->first)/2.0;
            }
            ans.push_back(median);
            left++;
            right++;
        }

        return ans;
    }
};