class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int n = arr.size();
        int leftSum = 0;
        int total = accumulate(arr.begin(),arr.end(),0);
        int rightSum = total;
        for(int i=0;i<n;i++){
            if(i != 0){
                leftSum = leftSum + arr[i-1]; 
            }
            rightSum = rightSum - arr[i];
            if(rightSum == leftSum){
                return i;
            }
        }
        return -1;
    }
};