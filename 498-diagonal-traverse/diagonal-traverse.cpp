class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        vector<int> arr;

        int total = row*col;
        int i = 0, j = 0;

        int dir = 1; // up-right = 1 and down-left = -1 
        while(arr.size() < total){
            arr.push_back(mat[i][j]);

            if(dir == 1){ // Moving Up-Right
                if(j == col-1){ //Hit the right Wall
                    i++;
                    dir = -1;
                } 
                else if(i == 0){ // Hit the top wall
                    j++;
                    dir = -1;
                }
                else{ // Between Process
                    i--;
                    j++;
                }

            }

            else{ // Moving Down-Right
                if(i == row-1){ // Hit the bottom wall
                    j++;
                    dir = 1;
                }
                else if(j == 0){ // Hit the left wall
                    i++;
                    dir = 1;
                }
                else{ // Between Process
                    i++; 
                    j--;
                }
            }
        }
        return arr;
    }
};