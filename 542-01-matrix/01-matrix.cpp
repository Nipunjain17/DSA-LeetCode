class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                }
                else{
                    mat[i][j] = INT_MAX;
                }
            }
        }

        vector<pair<int, int>> dirn = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            pair<int,int> v = q.front();
            q.pop();

            int i = v.first, j = v.second;

            for(auto dir : dirn){
                int x = i + dir.first;
                int y = j + dir.second;

                if(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] > mat[i][j] +1){
                    mat[x][y] = mat[i][j] +1;
                    q.push({x, y});
                }
            }
        }

        return mat;
    }
};