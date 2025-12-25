class Solution {
public:
    int diagonalSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0, j = 0;
        int sum = 0;
        while(i<n && j<m){
            sum += matrix[i][j];
            i++;
            j++;
        }
        
        i= 0, j = m-1;
        while(i<n && j>=0){
            sum += matrix[i][j];
            i++;
            j--;
        }
        i = n/2, j = m/2; 
        if(n%2 == 0) sum = sum + 0;
        else sum = sum - matrix[i][j];
        return sum;
    }
};