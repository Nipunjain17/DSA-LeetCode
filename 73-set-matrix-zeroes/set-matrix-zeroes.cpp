class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        bool row = false, col = false;
        
        // First Column
        for(int i=0; i<n; i++){
            if(mat[i][0] == 0) col = true;
        }
        
        // First row
        for(int j=0; j<m; j++){
            if(mat[0][j] == 0) row = true;
        }   
        // Marks Row and Column    
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(mat[i][j] == 0){
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        
        // Zero based markers 
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(mat[i][0] == 0 || mat[0][j] == 0){
                    mat[i][j] = 0;
                }
            }
        }
        
        // for first column
        if(col){
            for(int i=0; i<n; i++){
                mat[i][0] = 0;
            }
        }
        
        // for first row
        if(row){
            for(int j=0; j<m; j++){
                mat[0][j] = 0;
            }
        }   
    }
};