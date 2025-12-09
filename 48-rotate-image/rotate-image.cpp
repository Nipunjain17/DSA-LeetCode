class Solution {
public:
    // Transpose + Reverse
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step-1: Transpose the Matrix
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }    
        }

        // Step-2 : Reverse the Rows
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};