class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> matrix(n, vector<int>(n));  // create n x n matrix
        
        int total = n * n;
        int count = 1;

        int startingRow = 0, startingCol = 0;
        int endingRow = n - 1, endingCol = n - 1;

        while (count <= total) {

            // 1️⃣ Left to Right (Top Row)
            for(int col = startingCol; col <= endingCol && count <= total; col++) {
                matrix[startingRow][col] = count++;
            }
            startingRow++;

            // 2️⃣ Top to Bottom (Right Column)
            for(int row = startingRow; row <= endingRow && count <= total; row++) {
                matrix[row][endingCol] = count++;
            }
            endingCol--;

            // 3️⃣ Right to Left (Bottom Row)
            for(int col = endingCol; col >= startingCol && count <= total; col--) {
                matrix[endingRow][col] = count++;
            }
            endingRow--;

            // 4️⃣ Bottom to Top (Left Column)
            for(int row = endingRow; row >= startingRow && count <= total; row--) {
                matrix[row][startingCol] = count++;
            }
            startingCol++;
        }

        return matrix;
    }
};
