class Solution {
public:
    void solve(vector<vector<int>>& image, int i, int j, int oldColor, int newColor){
        int n = image.size();
        int m = image[0].size();

        // Boundary check + color check
        if (i < 0 || j < 0 || i >= n || j >= m ||
            image[i][j] != oldColor)
            return;

        // Color the current cell
        image[i][j] = newColor;

        // Visit 4 directions
        solve(image, i - 1, j, oldColor, newColor);
        solve(image, i + 1, j, oldColor, newColor);
        solve(image, i, j - 1, oldColor, newColor);
        solve(image, i, j + 1, oldColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;

        int oldColor = image[sr][sc];
        image[sr][sc] == color;

        solve(image, sr, sc, oldColor, color);
        return image;
    }
};