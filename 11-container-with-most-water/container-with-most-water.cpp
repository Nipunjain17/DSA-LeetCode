class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxi = 0;
        int current;
        while(left < right){
            int minHeight = min(height[left],height[right]);
            int weight = right-left;
            current = weight * minHeight;
            maxi = max(maxi,current);      
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxi;
    }
};