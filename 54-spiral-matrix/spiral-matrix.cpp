class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();

        int count = 0;
        int total = row * col;
        
        // index intialization 
        int startingRow = 0, startingCol = 0;
        int endingRow = row - 1, endingCol = col-1;

        vector<int> ans;
        while(count < total){

            // Print Starting Row
            for(int index=startingCol; count < total && index<=endingCol; index++){
                ans.push_back(matrix[startingRow][index]);
                count++;
            } 
            startingRow++;

            // Print Ending Column
            for(int index=startingRow; count<total && index<=endingRow; index++){
                ans.push_back(matrix[index][endingCol]);
                count++;
            } 
            endingCol--;

            // Print Ending Row
            for(int index=endingCol; count<total && index>=startingCol; index--){
                ans.push_back(matrix[endingRow][index]);
                count++;
            } 
            endingRow--;

            // print starting column
            for(int index=endingRow; count<total && index>=startingRow; index--){
                ans.push_back(matrix[index][startingCol]);
                count++;
            } 
            startingCol++;
        }
        return ans;
    }
};