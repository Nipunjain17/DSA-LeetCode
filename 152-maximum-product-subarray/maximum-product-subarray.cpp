class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();

        int maxi = arr[0] , maxp = arr[0] , minp = arr[0];

        for(int i=1;i<n;i++){
            int cp = maxp;

            maxp = max({arr[i] , arr[i] * maxp , arr[i] * minp});
            minp = min({arr[i] , cp * arr[i] , arr[i] * minp});

            maxi = max(maxi,maxp);
        }
        return maxi;
    }
};