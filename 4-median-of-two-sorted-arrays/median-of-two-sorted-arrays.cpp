class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> result;
        for(int i=0;i<n;i++){
            result.push_back(nums1[i]);
        }
        for(int i=n;i<m+n;i++){
            result.push_back(nums2[i-n]);
        }
        sort(result.begin(),result.end());
        int total = result.size();
        if(total % 2 == 1){
            return result[total/2];

        }
        else{
            double middle1 = result[total/2];
            double middle2 = result[total/2-1];
            return (middle1 + middle2)/2.0;
        }
    }
};