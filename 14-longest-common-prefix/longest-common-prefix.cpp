class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;
    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie{
public:
  TrieNode* root;

  Trie(){
    root = new TrieNode('\0');
  }  
  void insertutil(TrieNode* root, string word){
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }
    // indexing of character
    int index = word[0] - 'a';
    TrieNode* child;
    if(root->children[index] != NULL){ // present in trie
        child = root->children[index];
    }
    else{ // absent 
        child = new TrieNode(word[0]);
        root->children[index] = child;
        root->childCount++;
    }

    insertutil(child, word.substr(1));
  }

  void insert(string &word){
    insertutil(root, word);
  }

   void lcp(string str, string & ans){
        for(int i=0; i<str.length(); i++){
            char ch = str[i]; 

            if(root->childCount == 1){
                ans.push_back(ch);  
                // aage badho
                int index = ch - 'a';
                root = root->children[index];
            }
            else{
                break;
            }

            if(root->isTerminal == true){
                break;
            }
        }
    }
};


class Solution {
public:
   
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        for(int i=0; i<strs.size(); i++){
            if(strs[i].length() == 0){
                return "";
            }
            t.insert(strs[i]);
        }

        string ans = "";
        t.lcp(strs[0], ans);
        return ans;
    }
};