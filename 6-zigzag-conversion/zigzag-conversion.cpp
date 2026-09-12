class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.length() <= numRows){
            return s;
        }

        int index = 0, dirn = 1;
        vector<vector<char>> matrix(numRows);
        for(auto ch : s){
            matrix[index].push_back(ch);
            if(index == 0){
                dirn = 1;
            }
            else if(index == numRows -1){
                dirn = -1;
            }

            index += dirn;
        }

        string result;
        for(auto row : matrix){
            for(char c : row){
                result += c;
            }
        }
        return result;
    }
};