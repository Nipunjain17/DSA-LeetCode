class Solution {
public:
    void seive(vector<vector<int>>& mat, int n){
        vector<bool> prime(n+1,true);
        prime[0] = false;
        prime[1] = false;
        for(int i=2; i<=n; i++){
            if(prime[i]){
                for(int j=2*i; j<=n; j=j+i){
                    prime[j] = false;
                }
            }
        }
        
        int left = 2, right = n-1;
        while(left <= right){
            if(prime[left] && prime[right]){
                if(left + right < n) left++;

                else if(left + right > n) right--;
                
                else if(left + right == n){
                    mat.push_back({left,right});
                    left++;
                    right--;
                }
            }
            else{
                if(!prime[left])left++;
                if(!prime[right])right--;
            }
        }
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> mat;
        seive(mat,n);
        return mat;
    }
};