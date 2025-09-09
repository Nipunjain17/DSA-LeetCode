class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int n = prices.size();
        int bestBuy = prices[0];

        for(int i=0;i<n;i++){
            if(prices[i] > bestBuy){
                maxi = max(maxi,prices[i] - bestBuy);
            }
            bestBuy = min(bestBuy,prices[i]);
        }
        return maxi;
    }
};