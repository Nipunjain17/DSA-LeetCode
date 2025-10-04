class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int zeroPos = 0, twoPos = n-1;
        int current = 0;
        
        while(current <= twoPos){
            if(nums[current] == 0){
                swap(nums[zeroPos],nums[current]);
                zeroPos++;
                current++;
            }
            else if(nums[current] == 2){
                swap(nums[current],nums[twoPos]);
                twoPos--;
            }
            else{ // nums[current] == 1
                current++;
            }
        }
    }
};