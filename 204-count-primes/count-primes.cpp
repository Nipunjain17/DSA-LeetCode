// Sieve of Eratosthenes
// Time Complexity - O(n * log(log(n))
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1){
            return 0;
        }
        int freq = 0;
        vector<int> prime(n+1,true);

        prime[0] = false;
        prime[1] = false;

        for(int i=2; i<n; i++){
            if(prime[i]){
                freq++;
                for(int j=2*i; j<n; j=j+i){
                    prime[j] = 0;
                }
            }
        }
        return freq;
    }
};