class Solution {
private:
    vector<int> nextSmallerElement(const vector<int>& heights, int n){
        stack<int> st;
        st.push(-1);

        vector<int>ans(n);
        for(int i=n-1; i>=0; i--){
            int curr = heights[i];

            while(st.top() != -1 && heights[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElement(const vector<int>& heights, int n){
        stack<int> st;
        st.push(-1);

        vector<int>ans(n);
        for(int i=0; i<n; i++){
            int curr = heights[i];

            while(st.top() != -1 && heights[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights, int n) {

        vector<int>next(n);
        next = nextSmallerElement(heights,n);

        vector<int>prev(n);
        prev = prevSmallerElement(heights,n);

        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int height = heights[i];
            
            if(next[i] == -1) next[i] = n;
            int width = next[i] - prev[i] - 1;

            int currArea = height * width;
            area = max(currArea,area);
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> mat(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j]= matrix[i][j] - '0';
            }
        }

        int area = largestRectangleArea(mat[0],m);

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] != 0){
                    mat[i][j] += mat[i-1][j];
                }
                else{
                    mat[i][j] = 0;
                }

                area = max(area,largestRectangleArea(mat[i],m));
            } 
        }
        return area;
    }
};