class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;

        // Split s into words
        stringstream ss(s);

        while (ss >> word) {
            words.push_back(word);
        }

        // Number of characters and words must be same
        if (pattern.length() != words.size()) {
            return false;
        }

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for (int i = 0; i < pattern.length(); i++) {
            char ch = pattern[i];
            string w = words[i];

            // Check character -> word mapping
            if (mp1.count(ch)) {
                if (mp1[ch] != w) {
                    return false;
                }
            }
            else {
                mp1[ch] = w;
            }

            // Check word -> character mapping
            if (mp2.count(w)) {
                if (mp2[w] != ch) {
                    return false;
                }
            }
            else {
                mp2[w] = ch;
            }
        }

        return true;
    }
};