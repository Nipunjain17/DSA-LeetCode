class Solution {
public:
    int minimumSum(int num) {
        vector<int> arr;
        
        while(num > 0){
            int n = num %10;
            num = num /10;
            arr.push_back(n);
        }

        sort(arr.begin(), arr.end());

        int number = arr[0] *10 + arr[1] *10 + arr[2] + arr[3];
        return number;
    }
};