class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right){
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int l[n1],r[n2];
        int k = left;
        for(int i=0; i<n1; i++) l[i] = nums[k++];
        for(int i=0; i<n2; i++) r[i] = nums[k++];

        int i = 0, j = 0;
        k = left;
        while(i<n1 && j<n2){
            if(l[i] <= r[j]) nums[k++] = l[i++];
            else nums[k++] = r[j++];
        }

        while(i < n1) nums[k++] = l[i++];
        while(j < n2) nums[k++] = r[j++];
    }
    void mergeSort(vector<int>& nums, int left, int right){
        if(left < right){
            int mid = left + (right - left)/2;
            mergeSort(nums,left,mid);
            mergeSort(nums,mid+1,right);
            merge(nums,left,mid,right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int left = 0, right = nums.size() -1;
        mergeSort(nums,left,right);
        return nums;
    }
};