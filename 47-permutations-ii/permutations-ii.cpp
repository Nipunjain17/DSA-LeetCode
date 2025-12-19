class Solution {
private:
    void Solve_Recursion( int idx ,set<vector<int>>& s, vector<int>&nums){
        //    Base Case :
         if( idx == nums.size()){
             if(s.find(nums) == s.end()){
                s.insert(nums);
                return;
             }
             return ;
         }

         for( int j = idx ; j < nums.size() ; j++ ){
             swap( nums[idx] , nums[j] );
             Solve_Recursion( idx + 1 ,s , nums );
             swap( nums[idx] , nums[j]); 
         }
    } 
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        Solve_Recursion( 0 ,s, nums );
        return vector<vector<int>>(s.begin(), s.end());
    }
};