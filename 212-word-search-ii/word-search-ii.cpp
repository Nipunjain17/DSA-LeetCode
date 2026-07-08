class TrieNode{
  public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie {
  public:
    TrieNode* root;
    Trie() {
        // implement Trie
        root = new TrieNode('\0');
    }
    
    void InsertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        
        // assumption of index of characters in small letter
        int index = word[0] - 'a';
        TrieNode* child ;
        
        // present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{ // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        // recursion
        InsertUtil(child, word.substr(1));
    }
    void insert(string &word) {
        // insert word into Trie
        InsertUtil(root, word);
    }
};
class Solution {
private:
    void dfs(int x, int y, vector<vector<char>>& board, TrieNode* root, string word, set<string> &result){
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '#') return;

        if(root->children[board[x][y] -'a'] != NULL){
            word = word + board[x][y];    
            root = root->children[board[x][y] -'a'];

            if(root->isTerminal){
                result.insert(word);
            }
            char ch = board[x][y];
            board[x][y] = '#';

            dfs(x-1, y, board, root, word, result);
            dfs(x+1, y, board, root, word, result);
            dfs(x, y-1, board, root, word, result);
            dfs(x, y+1, board, root, word, result);

            board[x][y] = ch;
        } 

        return;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();

        Trie t;
        for(auto str : words){
            t.insert(str);
        }
        TrieNode* root = t.root;
        set<string> result;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dfs(i, j, board, root, "", result);
            }
        }
        
        vector<string> ans;
        for(auto str : result){
            ans.push_back(str);
        }
        return ans;
    }
};