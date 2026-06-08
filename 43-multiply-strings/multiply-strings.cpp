class Solution {
public:
    string multiply(string s1, string s2) {
        // Handle zero case
        if (s1 == "0" || s2 == "0") return "0";
        
        // Handle sign
        bool negative = false;
        if (s1[0] == '-') {
            negative = !negative;
            s1 = s1.substr(1);
        }
        if (s2[0] == '-') {
            negative = !negative;
            s2 = s2.substr(1);
        }
        
        // Remove leading zeros
        while (s1.size() > 1 && s1[0] == '0') s1.erase(0, 1);
        while (s2.size() > 1 && s2[0] == '0') s2.erase(0, 1);
        
        int n = s1.size(), m = s2.size();
        vector<int> res(n + m, 0);
        
        // Multiply like manual method
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + res[i + j + 1];
                
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        
        // Convert result to string
        string ans = "";
        for (int num : res) {
            if (!(ans.empty() && num == 0)) {
                ans.push_back(num + '0');
            }
        }
        
        if (ans.empty()) return "0";
        
        // Add negative sign if needed
        if (negative) ans = "-" + ans;
        
        return ans;
    }
};