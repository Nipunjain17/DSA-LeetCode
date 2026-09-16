class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> tri(n); 
        tri[0].push_back(1);

        if(n == 1){
            return tri;
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<=i; j++){
                if(j == 0){
                    tri[i].push_back(1);
                }
                else if(i == j){
                    tri[i].push_back(1);
                }
                else{
                    tri[i].push_back(tri[i-1][j-1] + tri[i-1][j]);
                }
            }
        }
        return tri;
    }
};