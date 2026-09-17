class Solution {
public:
    int tribonacci(int n) {
       if(n == 0) return 0;
       if(n == 1|| n == 2) return 1;

        int a = 0, b = 1;
        int curr = 1;
        int next;
        for(int i=3; i<=n; i++){
            next = a + b + curr;    
            a = b;
            b = curr;
            curr = next;
        }
        return next;
    }
};