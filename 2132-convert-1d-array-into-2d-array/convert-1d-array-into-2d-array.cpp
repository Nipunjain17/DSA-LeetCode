class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int n, int m) {
        if(n*m != original.size()) return {};

        vector<vector<int>> matrix(n, vector<int>(m));
        for(int i=0; i<n*m; i++){
            matrix[i/m][i%m] = original[i];
        }
        return matrix;
    }
};