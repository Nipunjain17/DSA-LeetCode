class Solution {
public:
    bool isPrime(int N){
        if(N == 1) return false;
        for(int i=2; i<=sqrt(N); i++){
            if(N%i == 0) return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        int maxi = 0;
        int i = 0, j = 0;
        while(i<n && j<m){
            int element = nums[i][j];
            if(isPrime(element)){
                maxi = max(element,maxi);
            }
            i++;
            j++;
        }

        i = 0, j = m-1;
        while(i<n && j>=0){
            int element = nums[i][j];
            if(isPrime(element)){
                maxi = max(element,maxi);
            }
            i++;
            j--;
        }
        return maxi;
    }
};