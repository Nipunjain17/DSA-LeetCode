class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d){
        data = d;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
    
    void InsertUtil(string word, TrieNode* root){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        TrieNode* child;
        int index = word[0] -'a';
        
        if(root->children[index]){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        InsertUtil(word.substr(1), child);
        return;
    }

    void Insert(string& word){
        InsertUtil(word, root);
    }

    void printSuggestion(TrieNode* curr, vector<string>& temp, string &prefix){
        if(curr == NULL || temp.size() == 3)return;

        if(curr->isTerminal ){
            temp.push_back(prefix);
        }

        for(char ch='a'; ch<='z'; ch++){
            TrieNode* next = curr->children[ch -'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> SuggestionSystem(string& word){
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";
       
        for(int i=0; i<word.length(); i++){
            char last = word[i];
            prefix.push_back(last);

            int index = last - 'a';
            TrieNode* curr = prev->children[index];

            if(curr == NULL){
                while(i < word.length()){
                    output.push_back({});
                    i++;
                }
                break;
            }

            vector<string>  temp;
            printSuggestion(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();

            prev = curr;
        }

        return output;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie t;

        for(auto word : products){
            t.Insert(word);
        }

        TrieNode* root = t.root;
        vector<vector<string>> sugg = t.SuggestionSystem(searchWord);
        return sugg;
    }
};