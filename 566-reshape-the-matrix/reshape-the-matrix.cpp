class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        int total = n * m;

        if(r*c != total) return mat;

        vector<vector<int>> ans(r,vector<int>(c));
        for(int i=0; i<total; i++){
            ans[i/c][i%c] = mat[i/m][i%m];
        }

        return ans;
    }
};